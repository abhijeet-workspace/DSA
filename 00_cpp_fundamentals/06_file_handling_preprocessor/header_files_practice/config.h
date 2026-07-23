// config.h
#pragma once

// Feature toggles and platform checks
#define PROJECT_NAME "HeaderFilesDemo"

// Conditional debug macro (can be passed via -DDEBUG on compile)
#ifdef DEBUG
#define LOG_DEBUG(msg) do { std::cerr << "DEBUG: " << (msg) << '\n'; } while(0)
#else
#define LOG_DEBUG(msg) do { } while(0)
#endif
