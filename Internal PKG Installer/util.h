#pragma once

#include "common.h"
#include <orbis/libkernel.h>
#include <fcntl.h>

int system_notification(const char* text, const char* iconName);
int ends_with(const char* haystack, const char* needle);
