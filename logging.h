#ifndef LOGGING_H
#define LOGGING_H

#include <stdio.h> 
#include <time.h>  

// Log levels
#define LOG_LEVEL_DEBUG 0
#define LOG_LEVEL_INFO  1
#define LOG_LEVEL_WARN  2
#define LOG_LEVEL_ERROR 3

#define CURRENT_LOG_LEVEL LOG_LEVEL_DEBUG

#define LOG_DEBUG(fmt, ...) \
    do { if (CURRENT_LOG_LEVEL <= LOG_LEVEL_DEBUG) fprintf(stderr, "[DEBUG] %s:%d:%s(): " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__); } while (0)

#define LOG_INFO(fmt, ...) \
    do { if (CURRENT_LOG_LEVEL <= LOG_LEVEL_INFO) fprintf(stderr, "[INFO] " fmt "\n", ##__VA_ARGS__); } while (0)

#define LOG_WARN(fmt, ...) \
    do { if (CURRENT_LOG_LEVEL <= LOG_LEVEL_WARN) fprintf(stderr, "[WARN] " fmt "\n", ##__VA_ARGS__); } while (0)

#define LOG_ERROR(fmt, ...) \
    do { if (CURRENT_LOG_LEVEL <= LOG_LEVEL_ERROR) fprintf(stderr, "[ERROR] %s:%d:%s(): " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__); } while (0)

#endif 