// Define Test Group here!!!
TEST_GROUP( CHANGE_INFORMATION) {
	MyTypeComparator comparator;
	// Setup
	void setup() {
		// Install Type Comparator
		mock().installComparator("INFO*", comparator);
		// Global information
		myinfo.name = "Suho Kwon";
		myinfo.age = 44;
		myinfo.alive = true;

		// New information
		newinfo.name = "MJ Yoon";
		newinfo.age = 44;
		newinfo.alive = true;
	}
	// Teardown
	void teardown() {
		// Restore default value
		newinfo.name = "";
		newinfo.age = 0;
		newinfo.alive = false;

		// Uninstall Type Comparator
		mock().removeAllComparators();
		// Clear Mock
		mock().clear();
	}
}
;
