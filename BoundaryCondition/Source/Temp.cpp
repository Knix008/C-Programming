/* ChangeInformation.c */
#include <string.h>
#include "AccessInformation.h"

bool change_information(INFO *info) {
	INFO *oldinfo;
	// Check parameter
	if (info == NULL) {
		return false;
	}

	// Print old information
	if ((oldinfo = get_information()) == NULL) {
		return false;
	}
	print_information(oldinfo);

	// Set new information
	if (set_information(info) == NULL) {
		return false;
	}
	return true;
}

