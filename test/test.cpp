#include "catch/catch_amalgamated.hpp"
#include <iostream>
#include "helper.cpp"
#include "AVL.cpp"
using namespace std;

// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
/*
TEST_CASE("Valid UFID"){
    REQUIRE(validateUFID("12345678") == true);
    REQUIRE(validateUFID("1234a678") == false);
    REQUIRE(validateUFID("1234)6789") == false);
    REQUIRE(validateUFID("12***6789") == false);
    REQUIRE(validateUFID("123~~789") == false);
}

TEST_CASE("Valid Name"){
    REQUIRE(validateName("Brandon") == true);
    REQUIRE(validateName("Scott") == true);
    REQUIRE(validateName("Tom") == true);
    REQUIRE(validateName("Skool Dan") == true);
    REQUIRE(validateName("Richard Daniels") == true);
    REQUIRE(validateName("Brand0n") == false);
}

TEST_CASE("Insert Function Test"){
    REQUIRE(insertInto("Brandon", "12345678") == true);

}
//These Tests test the class by itself and not the helperfunctions.
TEST_CASE("Create AVL using AVL class and test duplicates"){

    AVL* tree = AVL::getInstance();
    //2 valid
    //The better way to check for duplicates is to use a set and not the returned vector from the Inorder Traversal
    REQUIRE(tree->insertWrapper("Bob","00000001") == true);
    REQUIRE(tree->insertWrapper("Jane","00000002") == true);
    REQUIRE(tree->insertWrapper("Bob","00000001") == false);
    REQUIRE(tree->insertWrapper("Jane","00000002") == false);
    REQUIRE(tree->insertWrapper("Jack","00000004") == true);
    REQUIRE(tree->insertWrapper("Zack","00000003") == true);
    REQUIRE(tree->insertWrapper("Dack","00000007") == true);
    tree->resetTree();
}

//Insert and traverse works
TEST_CASE("Inorder Transversal with AVL class only"){
    AVL* tree = new AVL();
    REQUIRE(tree->insertWrapper("Bob","00000005") == true);
    REQUIRE(tree->insertWrapper("Jane","00000002") == true);
    REQUIRE(tree->insertWrapper("Derrick","00000008") == true);
    REQUIRE(tree->insertWrapper("Dave","00000003") == true);
    REQUIRE(tree->insertWrapper("Luna","00000001") == true);
    vector<string> UFID = tree->traverseWrapper();

    for(string value:UFID){
        cout<<value<<endl;
    }
    vector<string> compareIt = {"00000001","00000002","00000003","00000005","00000008"};
    for(int i = 0; i<UFID.size();i++){
        REQUIRE(UFID[i] == compareIt[i]);
    }
    tree->resetTree();

}
*/

TEST_CASE("Testing Height tracking for Tree"){
    AVL* tree = new AVL();
    tree->insertWrapper("Jackery","00000005");
    tree->insertWrapper("dave","00000002");
    tree->insertWrapper("dave","00000006");
    tree->insertWrapper("dave","00000003");
    vector<string>levelOrder = tree->levelOrderWrapper();
    vector<string>comparetor = {"00000005","00000002","00000006","00000003"};
    for(int i = 0; i<levelOrder.size();i++){
        REQUIRE(levelOrder[i] == comparetor[i]);
    }

}


/*
TEST_CASE("Test 2", "[flag]"){
	// you can also use "sections" to share setup code between tests, for example:
	int one = 1;

	SECTION("num is 2") {
		int num = one + 1;
		REQUIRE(num == 2);
	};

	SECTION("num is 3") {
		int num = one + 2;
		REQUIRE(num == 3);
	};

	// each section runs the setup code independently to ensure that they don't affect each other
}
*/
// you must write 5 unique, meaningful tests for credit on the testing portion of this project!

// the provided test from the template is below.

TEST_CASE("Example BST Insert", "[flag]"){
	/*
		MyAVLTree tree;   // Create a Tree object
		tree.insert(3);
		tree.insert(2);
		tree.insert(1);
		std::vector<int> actualOutput = tree.inorder();
		std::vector<int> expectedOutput = {1, 2, 3};
		REQUIRE(expectedOutput.size() == actualOutput.size());
		REQUIRE(actualOutput == expectedOutput);
	*/
}
