#include <stdio.h>

// model specific constants
# define GUID "{d7bac2e2-f3c4-fc14-357b-41ecbe1c538d}"

// no runtime resources
#define RESOURCE_LOCATION "file:///C:/Users/schyan01/git/fmu_risingedge/" // absolut path to the unziped fmu
#include "fmi2Functions.h"

// callback functions
static void cb_logMessage(fmi2ComponentEnvironment componentEnvironment, fmi2String instanceName, fmi2Status status, fmi2String category, fmi2String message, ...) {
	printf("%s\n", message);
}

static void* cb_allocateMemory(size_t nobj, size_t size) {
	return calloc(nobj, size);
}

static void cb_freeMemory(void* obj) {
	free(obj);
}

#define CHECK_STATUS(S) { status = S; if (status != fmi2OK) goto TERMINATE; }

int main(int argc, char *argv[]) {

	fmi2Status status = fmi2OK;

	fmi2CallbackFunctions callbacks = {cb_logMessage, cb_allocateMemory, cb_freeMemory, NULL, NULL};
	
	fmi2Component c = RisingEdge_fmi2Instantiate("instance1", fmi2CoSimulation, GUID, RESOURCE_LOCATION, &callbacks, fmi2False, fmi2False);
	
	if (!c) return 1;
	
	
TERMINATE:

	// clean up
	if (status < fmi2Fatal) {
		RisingEdge_fmi2FreeInstance(c);
	}
	
	return status;
}
