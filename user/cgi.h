#ifndef CGI_H
#define CGI_H

#include "httpd.h"

int cgiReadFlash(HttpdConnData *connData);
void tplCounter(HttpdConnData *connData, char *token, void **arg);

int cgiCommand(HttpdConnData *connData);

#endif