#ifndef __LOG_H__
#define __LOG_H__

#define LOG_LOCAL_LEVEL         3

typedef enum {
    LOG_NONE,   /*!< No log output */
    LOG_ERROR,  /*!< Critical errors, software module can not recover on its own */
    LOG_WARN,   /*!< Error conditions from which recovery measures have been taken */
    LOG_INFO,   /*!< Information messages which describe normal flow of events */
    LOG_DEBUG,  /*!< Extra information which is not necessary for normal use (values, pointers, sizes, etc). */
    LOG_VERBOSE /*!< Bigger chunks of debugging information, or frequent messages which can potentially flood the output. */
} log_level_t;

#define LOG_FORMAT(letter, format)  #letter " (%d) %s: " format "\n"
#define LOGE( tag, format, ... )  if (LOG_LOCAL_LEVEL >= LOG_ERROR)   { log_write(LOG_FORMAT(E, format), log_timestamp(), tag, ##__VA_ARGS__); }
#define LOGW( tag, format, ... )  if (LOG_LOCAL_LEVEL >= LOG_WARN)    { log_write(LOG_FORMAT(W, format), log_timestamp(), tag, ##__VA_ARGS__); }
#define LOGI( tag, format, ... )  if (LOG_LOCAL_LEVEL >= LOG_INFO)    { log_write(LOG_FORMAT(I, format), log_timestamp(), tag, ##__VA_ARGS__); }
#define LOGD( tag, format, ... )  if (LOG_LOCAL_LEVEL >= LOG_DEBUG)   { log_write(LOG_FORMAT(D, format), log_timestamp(), tag, ##__VA_ARGS__); }
#define LOGV( tag, format, ... )  if (LOG_LOCAL_LEVEL >= LOG_VERBOSE) { log_write(LOG_FORMAT(V, format), log_timestamp(), tag, ##__VA_ARGS__); }

unsigned int log_timestamp(void);
void log_write(const char* format, ...) __attribute__ ((format (printf, 1, 2)));

#endif /* __LOG_H_ */