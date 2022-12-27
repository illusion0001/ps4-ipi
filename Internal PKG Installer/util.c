#include "util.h"

int system_notification(const char* text) {
	OrbisNotificationRequest NotificationBuffer;
	NotificationBuffer.type = 0;
	NotificationBuffer.unk3 = 0; 
	NotificationBuffer.useIconImageUri = 1;
	NotificationBuffer.targetId = -1;
	snprintf(NotificationBuffer.iconUri, sizeof(NotificationBuffer.iconUri), "cxml://psnotification/tex_icon_system");
	strncpy(NotificationBuffer.message, text, sizeof(NotificationBuffer.message));
	sceKernelSendNotificationRequest(0, &NotificationBuffer, sizeof(NotificationBuffer), 0);
	return 0;
}

int ends_with(const char* haystack, const char* needle) {
	ptrdiff_t diff;
	int i;
	assert(haystack != NULL);
	assert(needle != NULL);
	diff = strlen(haystack) - strlen(needle);
	if (diff < 0) {
		return -1;
	}
	for (i = 0; needle[i] != '\0'; ++i) {
		if (needle[i] != haystack[i + diff]) {
			return -2;
		}
	}
	return 0;
}
