/// <summary>
/// Empty Project for SFML[2.4.2]
/// 
/// 
/// @author Peter Lowe
/// @date May 21017
/// </summary>

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include <iostream>
#include "InitialMyMatrix3.h"
#include "MyVector3.h"

/// <summary>
/// main enrtry point
/// </summary>
/// <returns>zero</returns>
int main()
{
	// matrix that will be changed 
	MyMatrix3 matrixOne = { 1.0,1.0,1.0
						,1.0,1.0,1.0
						,1.0,1.0,1.0 };
	// ----------------------------------------------
	// matrix that will modify the first 
	MyMatrix3 matrixTwo = { 2.4 , 5 ,7,
							-1.56, 2, 3.14,
							1.56,-2, -1 };
	// ---------------------------------------------
	// matrix one after the math stuff so as to not corrupt the first matrix's value
	MyMatrix3 matrixThree = { 0.0,0.0,0.0,
							  0.0,0.0,0.0,
							  0.0,0.0,0.0 };
	// ----------------------------------------------

	std::cout << "---First matrix---" << std::endl;
	std::cout << matrixOne.toString() << std::endl;
	std::cout << "" << std::endl;
	// ----------------------------------------------

	std::cout << "--- Operator == ---" << std::endl;
	if (matrixOne.operator==(matrixTwo))
	{
		std::cout << "matrices are the same" << std::endl;
	}
	else
	{
		std::cout << "matrices are not the same. " << std::endl;
	}
	std::cout << "" << std::endl;
	// ----------------------------------------------

	std::cout << "--- Operator != ---" << std::endl;
	if (matrixOne.operator!=(matrixTwo))
	{
		std::cout << "Matrices are not equivalent" << std::endl;
	}
	else
	{
		std::cout << "Matrices are the same. " << std::endl;
	}
	std::cout << "" << std::endl;
	// ----------------------------------------------

	std::cout << "--- Matrix Multiplcation x Matrix ---" << std::endl;
	std::cout << matrixOne.operator*(matrixTwo).toString();
	std::cout << "Expected Outcome" << std::endl;
	std::cout << "2.4, 5, 9.14, 2.4, 5, 9.14, 2.4, 5, 9.14"<< std::endl;
	std::cout << "" << std::endl;
	// ----------------------------------------------

	std::cout << " -- Matrix Maltiplication x 3D Vector ---" << std::endl;
	MyVector3 vectorOne = { -4.32, 3, 7.54 };
	std::cout << matrixOne.operator*(vectorOne).toString() << std::endl;
	std::cout << "Expected Outcome" << std::endl;
	std::cout << "6.2, 6.2, 6.2" << std::endl;
	std::cout << "" << std::endl;
	// ----------------------------------------------

	std::cout << "--- Matrix Multiplication by a Scalar ---" << std::endl;
	const double scalar = 5;
	std::cout << matrixOne.operator*(scalar).toString() << std::endl;
	std::cout << "Expecter Outcome" << std::endl;
	std::cout << "5, 5, 5, 5, 5, 5 , 5, 5, 5" << std::endl; 
	std::cout << "" << std::endl;
	// ----------------------------------------------

	std::cout << "--- Transpose of a Matrix ---" << std::endl;
	std::cout << matrixTwo.transpose().toString() << std::endl;
	std::cout << "Expected outcome" << std::endl;
	std::cout << "2.4, -1.56, 1.56, 5, 2, -2, 7, 3.14, -1" << std::endl;
	std::cout << "" << std::endl;
	// ----------------------------------------------
	
	std::cout << "--- Derterminate of a Matrix" << std::endl;
	std::cout << std::to_string(matrixTwo.determinant()) << std::endl;
	std::cout << "Expected Outcome" << std::endl;
	std::cout << "26.964" << std::endl;
	// oh noey 

	std::system("pause");
	return 0;
}