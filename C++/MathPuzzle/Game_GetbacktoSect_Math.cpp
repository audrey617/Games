// FILENAME:   Game_GetbacktoSect_Math.cpp 
// PROGRAMMER: Audrey
// DATE:       1/14/2021
// COMPILER:   clang++
// REQUIRED:   Game_GetbacktoSect_Math.cpp 
// PURPOSE:    A simple number math game
// NOTE:
// 1. Simple number puzzle game
// 2. Solve the math lock
// 3. Need to find a valid combination of codes
// 4. from easy to hard
// The math design follows the unreal engine class. Check UnrealCourse2019/TripleX in github


#include <iostream>
#include <ctime>

//prototype
void print_startmessage();
bool play_mathgame(int);


int main(){

	srand(time(NULL));// Create new random sequence based on the time of day

	int level = 1;
	int count = 0;
	const int max_level = 7;
	const int max_loop = 15;

	print_startmessage();

	while(true){

        std::cin.clear(); // unset failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
		level += play_mathgame(level);

		if(level == max_level){
			std::cout << "You break into the room and teleport back. Congrats!"<< std::endl;
			break;
		}

		if(count == max_loop){
			std::cout << "You spent too long in the trial and ran out of food. You were rescued by your sect mentor. Game end "<< std::endl;
			break;
		}

		count++;

	}


	return 0;
}

// Print start messages to the terminal
void print_startmessage(){
	std::cout << "You are a young disciple of Spirit Blade Cultivation Sect.\n"
	<< "Three days ago, you entered a special trial and need to pass it...\n"
	<< "Now, you face the last challenge - breaking into a secured room to teleport back to the sect.\n"
	<< "The room is protected by codes. Enter the right codes and then you are all set\n\n"	
	<< "Press enter to start\n\n";
}

bool play_mathgame(int level){

	std::cout << "Code level - " << level << std::endl;
	
	// Generate code
    // Declare 3 number code
    const int code1 = rand() % level + level; 
    const int code2 = rand() % level + level;
    const int code3 = rand() % level + level;
   
    const int sum_code = code1 + code2 + code3;
    const int product_code = code1 * code2 * code3;

    // Print sum and product to the terminal
    std::cout << std::endl;
    std::cout << "There are 3 numbers in the code\n" ;
    std::cout << "The codes add up to: " << sum_code << std::endl;
    std::cout << "The codes multiply to give: " << product_code << std::endl;

    std::cout << "Enter the correct code:\n\n";
    int guess1, guess2, guess3;
    std::cin >> guess1 >> guess2 >> guess3;

    const int sum_guess = guess1 + guess2 + guess3;
    const int product_guess = guess1 * guess2 * guess3;

    // Check if the player guess is correct
    if (sum_guess == sum_code && product_guess == product_code){
        std::cout << "\nNext level code is unlocked." << std::endl;
        return true;
    }
    std::cout << "\nYou didn't pass the current level." << std::endl;
    return false;
}
