#!/usr/bin/env bash
# Build plain-text + HTML notification emails for DSA GitHub Actions.
# Required env: KIND (merged|cancelled|ci_failed), LOGIN, REPO
# Shared optional: PR_NUMBER, PR_TITLE, PR_URL, BASE_REF, HEAD_REF, AUTHOR,
#                  MERGED_BY, MERGE_SHA, CLOSED_BY, RUN_URL, RUN_ID,
#                  BRANCH, SHA, EVENT_NAME, FAILURE_LOG, JOB_NAME
set -euo pipefail


KIND="${KIND:?KIND is required}"
LOGIN="${LOGIN:?LOGIN is required}"
REPO="${REPO:?REPO is required}"

OUT_TXT="${OUT_TXT:-/tmp/notify-email.txt}"
OUT_HTML="${OUT_HTML:-/tmp/notify-email.html}"
OUT_SUBJECT_FILE="${OUT_SUBJECT_FILE:-/tmp/notify-subject.txt}"

escape_html() {
  python3 -c 'import html,sys; print(html.escape(sys.argv[1]))' "$1"
}

REPO_URL="https://github.com/${REPO}"
PR_NUMBER="${PR_NUMBER:-}"
PR_TITLE="${PR_TITLE:-}"
PR_URL="${PR_URL:-}"
BASE_REF="${BASE_REF:-}"
HEAD_REF="${HEAD_REF:-}"
AUTHOR="${AUTHOR:-$LOGIN}"
MERGED_BY="${MERGED_BY:-}"
MERGE_SHA="${MERGE_SHA:-}"
CLOSED_BY="${CLOSED_BY:-}"
RUN_URL="${RUN_URL:-}"
RUN_ID="${RUN_ID:-}"
BRANCH="${BRANCH:-}"
SHA="${SHA:-}"
EVENT_NAME="${EVENT_NAME:-}"
JOB_NAME="${JOB_NAME:-Compile}"
FAILURE_LOG="${FAILURE_LOG:-No failure log was captured. Open the workflow run for full details.}"

SHORT_SHA=""
COMMIT_URL=""
if [[ -n "$MERGE_SHA" ]]; then
  SHORT_SHA="${MERGE_SHA:0:7}"
  COMMIT_URL="https://github.com/${REPO}/commit/${MERGE_SHA}"
elif [[ -n "$SHA" ]]; then
  SHORT_SHA="${SHA:0:7}"
  COMMIT_URL="https://github.com/${REPO}/commit/${SHA}"
fi

# Truncate failure log for email size limits
FAILURE_LOG_TRIMMED="$(printf '%s' "$FAILURE_LOG" | tail -n 80)"
if [[ ${#FAILURE_LOG_TRIMMED} -gt 12000 ]]; then
  FAILURE_LOG_TRIMMED="${FAILURE_LOG_TRIMMED: -12000}"
fi

H_LOGIN="$(escape_html "$LOGIN")"
H_REPO="$(escape_html "$REPO")"
H_TITLE="$(escape_html "${PR_TITLE:-n/a}")"
H_BASE="$(escape_html "${BASE_REF:-n/a}")"
H_HEAD="$(escape_html "${HEAD_REF:-${BRANCH:-n/a}}")"
H_AUTHOR="$(escape_html "$AUTHOR")"
H_MERGED_BY="$(escape_html "${MERGED_BY:-n/a}")"
H_CLOSED_BY="$(escape_html "${CLOSED_BY:-n/a}")"
H_SHORT="$(escape_html "${SHORT_SHA:-n/a}")"
H_BRANCH="$(escape_html "${BRANCH:-n/a}")"
H_EVENT="$(escape_html "${EVENT_NAME:-n/a}")"
H_JOB="$(escape_html "$JOB_NAME")"
H_LOG="$(escape_html "$FAILURE_LOG_TRIMMED")"

row() {
  local label="$1" value="$2" last="${3:-}"
  local border="border-bottom:1px solid #d0d7de;"
  [[ "$last" == "1" ]] && border=""
  cat <<ROW
<tr>
  <td style="padding:10px 14px;${border}color:#57606a;width:120px;vertical-align:top;">${label}</td>
  <td style="padding:10px 14px;${border}">${value}</td>
</tr>
ROW
}

cta() {
  local href="$1" label="$2" bg="$3"
  cat <<CTA
<table role="presentation" cellpadding="0" cellspacing="0" style="margin-top:24px;">
  <tr>
    <td style="background:${bg};border-radius:6px;">
      <a href="${href}" style="display:inline-block;padding:10px 18px;color:#ffffff;text-decoration:none;font-size:14px;font-weight:600;">
        ${label}
      </a>
    </td>
  </tr>
</table>
CTA
}

wrap_html() {
  local accent="$1" eyebrow="$2" heading="$3" intro="$4" rows_html="$5" cta_html="$6"
  cat > "$OUT_HTML" <<EOF
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <title>${heading}</title>
</head>
<body style="margin:0;padding:0;background:#f4f5f7;font-family:-apple-system,BlinkMacSystemFont,'Segoe UI',Helvetica,Arial,sans-serif;color:#24292f;">
  <table role="presentation" width="100%" cellpadding="0" cellspacing="0" style="background:#f4f5f7;padding:32px 12px;">
    <tr>
      <td align="center">
        <table role="presentation" width="100%" cellpadding="0" cellspacing="0" style="max-width:580px;background:#ffffff;border:1px solid #d0d7de;border-radius:8px;overflow:hidden;">
          <tr>
            <td style="background:${accent};padding:20px 24px;color:#ffffff;">
              <div style="font-size:13px;letter-spacing:0.04em;text-transform:uppercase;opacity:0.9;">${eyebrow}</div>
              <div style="font-size:22px;font-weight:600;margin-top:6px;">${heading}</div>
            </td>
          </tr>
          <tr>
            <td style="padding:24px;">
              <p style="margin:0 0 16px;font-size:15px;line-height:1.5;">Hi <strong>@${H_LOGIN}</strong>,</p>
              <p style="margin:0 0 20px;font-size:15px;line-height:1.5;">${intro}</p>
              <table role="presentation" width="100%" cellpadding="0" cellspacing="0" style="border:1px solid #d0d7de;border-radius:6px;font-size:14px;">
                ${rows_html}
              </table>
              ${cta_html}
            </td>
          </tr>
          <tr>
            <td style="padding:14px 24px;background:#f6f8fa;border-top:1px solid #d0d7de;font-size:12px;color:#57606a;">
              Sent automatically by the DSA notifier · do not reply
            </td>
          </tr>
        </table>
      </td>
    </tr>
  </table>
</body>
</html>
EOF
}

case "$KIND" in
  merged)
    SUBJECT="[DSA] Merged #${PR_NUMBER}: ${PR_TITLE}"
    cat > "$OUT_TXT" <<EOF
Hi @${LOGIN},

Your pull request was merged successfully into ${BASE_REF}.

Repository : ${REPO}
PR         : #${PR_NUMBER} — ${PR_TITLE}
Branches   : ${HEAD_REF} → ${BASE_REF}
Author     : @${AUTHOR}
Merged by  : @${MERGED_BY}
Commit     : ${SHORT_SHA}
PR URL     : ${PR_URL}
Commit URL : ${COMMIT_URL}

— DSA notifier
EOF
    ROWS="$(row Title "<strong>${H_TITLE}</strong>")"
    ROWS+="$(row Repository "<a href=\"${REPO_URL}\" style=\"color:#0969da;text-decoration:none;\">${H_REPO}</a>")"
    ROWS+="$(row Branches "<code style=\"background:#f6f8fa;padding:2px 6px;border-radius:4px;font-size:13px;\">${H_HEAD}</code> → <code style=\"background:#f6f8fa;padding:2px 6px;border-radius:4px;font-size:13px;\">${H_BASE}</code>")"
    ROWS+="$(row Author "@${H_AUTHOR}")"
    ROWS+="$(row "Merged by" "@${H_MERGED_BY}")"
    ROWS+="$(row Commit "<a href=\"${COMMIT_URL}\" style=\"color:#0969da;text-decoration:none;font-family:ui-monospace,SFMono-Regular,Menlo,Consolas,monospace;\">${H_SHORT}</a>" 1)"
    CTA_HTML="$(cta "$PR_URL" "View pull request" "#1a7f37")"
    wrap_html "#1a7f37" "DSA · Merge success" "Pull request merged" \
      "Your pull request <a href=\"${PR_URL}\" style=\"color:#0969da;text-decoration:none;font-weight:600;\">#${PR_NUMBER}</a> was merged into <code style=\"background:#f6f8fa;padding:2px 6px;border-radius:4px;font-size:13px;\">${H_BASE}</code>." \
      "$ROWS" "$CTA_HTML"
    ;;

  cancelled)
    SUBJECT="[DSA] Closed #${PR_NUMBER}: ${PR_TITLE}"
    cat > "$OUT_TXT" <<EOF
Hi @${LOGIN},

Your pull request was closed without merging (cancelled / not merged).

Repository : ${REPO}
PR         : #${PR_NUMBER} — ${PR_TITLE}
Branches   : ${HEAD_REF} → ${BASE_REF}
Author     : @${AUTHOR}
Closed by  : @${CLOSED_BY}
PR URL     : ${PR_URL}

No code from this PR was merged into ${BASE_REF}.

— DSA notifier
EOF
    ROWS="$(row Title "<strong>${H_TITLE}</strong>")"
    ROWS+="$(row Repository "<a href=\"${REPO_URL}\" style=\"color:#0969da;text-decoration:none;\">${H_REPO}</a>")"
    ROWS+="$(row Branches "<code style=\"background:#f6f8fa;padding:2px 6px;border-radius:4px;font-size:13px;\">${H_HEAD}</code> → <code style=\"background:#f6f8fa;padding:2px 6px;border-radius:4px;font-size:13px;\">${H_BASE}</code>")"
    ROWS+="$(row Author "@${H_AUTHOR}")"
    ROWS+="$(row "Closed by" "@${H_CLOSED_BY}")"
    ROWS+="$(row Status "<span style=\"color:#9a6700;font-weight:600;\">Closed without merge</span>" 1)"
    CTA_HTML="$(cta "$PR_URL" "View pull request" "#9a6700")"
    wrap_html "#9a6700" "DSA · PR closed" "Pull request cancelled" \
      "Your pull request <a href=\"${PR_URL}\" style=\"color:#0969da;text-decoration:none;font-weight:600;\">#${PR_NUMBER}</a> was <strong>closed without merging</strong> into <code style=\"background:#f6f8fa;padding:2px 6px;border-radius:4px;font-size:13px;\">${H_BASE}</code>." \
      "$ROWS" "$CTA_HTML"
    ;;

  ci_failed)
    SUBJECT="[DSA] CI failed${PR_NUMBER:+ on #${PR_NUMBER}}: ${PR_TITLE:-${BRANCH:-build}}"
    cat > "$OUT_TXT" <<EOF
Hi @${LOGIN},

CI failed. Fix the issue below and push again.

Repository : ${REPO}
Event      : ${EVENT_NAME}
Branch     : ${BRANCH}
Commit     : ${SHORT_SHA}
Job        : ${JOB_NAME}
${PR_NUMBER:+PR         : #${PR_NUMBER} — ${PR_TITLE}
}${PR_URL:+PR URL     : ${PR_URL}
}Run URL    : ${RUN_URL}

--- Failure log (tail) ---
${FAILURE_LOG_TRIMMED}
--- end ---

— DSA notifier
EOF
    PR_ROW=""
    if [[ -n "$PR_NUMBER" ]]; then
      PR_ROW="$(row PR "<a href=\"${PR_URL}\" style=\"color:#0969da;text-decoration:none;font-weight:600;\">#${PR_NUMBER}</a> — ${H_TITLE}")"
    fi
    ROWS="$(row Repository "<a href=\"${REPO_URL}\" style=\"color:#0969da;text-decoration:none;\">${H_REPO}</a>")"
    ROWS+="$(row Event "${H_EVENT}")"
    ROWS+="$(row Branch "<code style=\"background:#f6f8fa;padding:2px 6px;border-radius:4px;font-size:13px;\">${H_BRANCH}</code>")"
    ROWS+="$(row Commit "<a href=\"${COMMIT_URL}\" style=\"color:#0969da;text-decoration:none;font-family:ui-monospace,SFMono-Regular,Menlo,Consolas,monospace;\">${H_SHORT}</a>")"
    ROWS+="$(row Job "${H_JOB}")"
    ROWS+="${PR_ROW}"
    ROWS+="$(row Status "<span style=\"color:#cf222e;font-weight:600;\">Failed</span>" 1)"
    LOG_BLOCK="<div style=\"margin-top:20px;\"><div style=\"font-size:13px;font-weight:600;margin-bottom:8px;color:#cf222e;\">Failure log (tail)</div><pre style=\"margin:0;padding:12px;background:#0d1117;color:#f0f6fc;border-radius:6px;font-size:12px;line-height:1.45;overflow-x:auto;white-space:pre-wrap;word-break:break-word;\">${H_LOG}</pre></div>"
    CTA_TARGET="${RUN_URL:-$PR_URL}"
    CTA_LABEL="View failed run"
    [[ -z "$RUN_URL" && -n "$PR_URL" ]] && CTA_LABEL="View pull request"
    CTA_HTML="$(cta "$CTA_TARGET" "$CTA_LABEL" "#cf222e")${LOG_BLOCK}"
    INTRO="Continuous integration <strong>failed</strong>. Review the log excerpt below, fix the issue, then push again."
    if [[ -n "$PR_NUMBER" ]]; then
      INTRO="CI failed for pull request <a href=\"${PR_URL}\" style=\"color:#0969da;text-decoration:none;font-weight:600;\">#${PR_NUMBER}</a>. Review the log excerpt below, fix the issue, then push again."
    fi
    wrap_html "#cf222e" "DSA · CI failure" "Build / tests failed" "$INTRO" "$ROWS" "$CTA_HTML"
    ;;

  *)
    echo "Unknown KIND: $KIND" >&2
    exit 1
    ;;
esac

printf '%s\n' "$SUBJECT" > "$OUT_SUBJECT_FILE"
echo "Built notify email kind=${KIND} subject=$(cat "$OUT_SUBJECT_FILE")"
