#ifndef _MATCHERS_H__
#define _MATCHERS_H__

#include <pcre.h>
#include <python2.7/Python.h>

#define MATCHER_MAX_LEN 2048 
#define MATCHER_MAX_RESPONSE 32000 // maximum text response len 
#define MATCHERS_DEFAULT_FILENAME "matchers.conf"

#define PYFUNCNAME "forge_response"
#define PYTHONPATH "." // python modules path

struct matcher_entry {
    char name[64];
    pcre *match;
    pcre *ignore;
    u_char *response;
    u_int response_len;
    PyObject *pyfunc;
    u_int options;
    #define MATCHER_OPTION_RESET 1
    u_int proto;
    #define MATCHER_PROTO_ANY 1
    #define MATCHER_PROTO_UDP 2
    #define MATCHER_PROTO_TCP 3
    u_int src_port;
    u_int dst_port;
    struct matcher_entry *next;
};

struct matcher_entry *parse_matchers_file(char *macher_file_path);

#endif
