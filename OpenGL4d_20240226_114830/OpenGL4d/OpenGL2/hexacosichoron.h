#pragma once
//#include<GLFW/glfw3.h>
//#include<vec4.hpp>
namespace hexacosichoron {
	static glm::vec4 vertices4D[] =
	{
    glm::vec4(0.25, 0.25, 0.25, 0.25),
    glm::vec4(0.25, 0.25, 0.25, - 0.25),
    glm::vec4(0.25, 0.25, - 0.25, 0.25),
    glm::vec4(0.25, - 0.25, 0.25, 0.25),
    glm::vec4(- 0.25, 0.25, 0.25, 0.25),
    glm::vec4(0.25, 0.25, - 0.25, - 0.25),
    glm::vec4(0.25, - 0.25, - 0.25, 0.25),
    glm::vec4(0.25, - 0.25, 0.25, - 0.25),
    glm::vec4(- 0.25, 0.25, 0.25, - 0.25),
    glm::vec4(- 0.25, 0.25, - 0.25, 0.25),
    glm::vec4(- 0.25, - 0.25, 0.25, 0.25),
    glm::vec4(0.25, - 0.25, - 0.25, - 0.25),
    glm::vec4(- 0.25, 0.25, - 0.25, - 0.25),
    glm::vec4(- 0.25, - 0.25, 0.25, - 0.25),
    glm::vec4(- 0.25, - 0.25, - 0.25, 0.25),
    glm::vec4(- 0.25, - 0.25, - 0.25, - 0.25),
    glm::vec4(0.5, 0, 0, 0),
    glm::vec4(0, 0.5, 0, 0),
    glm::vec4(0, 0, 0.5, 0),
    glm::vec4(0, 0, 0, 0.5),
    glm::vec4(- 0.5, 0, 0, 0),
    glm::vec4(0, - 0.5, 0, 0),
    glm::vec4(0, 0, - 0.5, 0),
    glm::vec4(0, 0, 0, - 0.5),
    glm::vec4(0.404508497187473, 0.25, 0.154508497187474, 0),
    glm::vec4(0.404508497187473, 0.154508497187474, 0, 0.25),
    glm::vec4(0.404508497187473, 0, 0.25, 0.154508497187474),
    glm::vec4(0.25, 0.404508497187473, 0, 0.154508497187474),
    glm::vec4(0.25, 0.154508497187474, 0.404508497187473, 0),
    glm::vec4(0.25, 0, 0.154508497187474, 0.404508497187473),
    glm::vec4(0.154508497187474, 0.404508497187473, 0.25, 0),
    glm::vec4(0.154508497187474, 0.25, 0, 0.404508497187473),
    glm::vec4(0.154508497187474, 0, 0.404508497187473, 0.25),
    glm::vec4(0, 0.404508497187473, 0.154508497187474, 0.25),
    glm::vec4(0, 0.25, 0.404508497187473, 0.154508497187474),
    glm::vec4(0, 0.154508497187474, 0.25, 0.404508497187473),
    glm::vec4(0.404508497187473, 0.25, - 0.154508497187474, 0),
    glm::vec4(0.404508497187473, - 0.154508497187474, 0, 0.25),
    glm::vec4(0.404508497187473, 0, 0.25, - 0.154508497187474),
    glm::vec4(0.25, 0.404508497187473, 0, - 0.154508497187474),
    glm::vec4(0.25, - 0.154508497187474, 0.404508497187473, 0),
    glm::vec4(0.25, 0, - 0.154508497187474, 0.404508497187473),
    glm::vec4(- 0.154508497187474, 0.404508497187473, 0.25, 0),
    glm::vec4(- 0.154508497187474, 0.25, 0, 0.404508497187473),
    glm::vec4(- 0.154508497187474, 0, 0.404508497187473, 0.25),
    glm::vec4(0, 0.404508497187473, - 0.154508497187474, 0.25),
    glm::vec4(0, 0.25, 0.404508497187473, - 0.154508497187474),
    glm::vec4(0, - 0.154508497187474, 0.25, 0.404508497187473),
    glm::vec4(0.404508497187473, - 0.25, 0.154508497187474, 0),
    glm::vec4(0.404508497187473, 0.154508497187474, 0, - 0.25),
    glm::vec4(0.404508497187473, 0, - 0.25, 0.154508497187474),
    glm::vec4(- 0.25, 0.404508497187473, 0, 0.154508497187474),
    glm::vec4(- 0.25, 0.154508497187474, 0.404508497187473, 0),
    glm::vec4(- 0.25, 0, 0.154508497187474, 0.404508497187473),
    glm::vec4(0.154508497187474, 0.404508497187473, - 0.25, 0),
    glm::vec4(0.154508497187474, - 0.25, 0, 0.404508497187473),
    glm::vec4(0.154508497187474, 0, 0.404508497187473, - 0.25),
    glm::vec4(0, 0.404508497187473, 0.154508497187474, - 0.25),
    glm::vec4(0, - 0.25, 0.404508497187473, 0.154508497187474),
    glm::vec4(0, 0.154508497187474, - 0.25, 0.404508497187473),
    glm::vec4(0.404508497187473, - 0.25, - 0.154508497187474, 0),
    glm::vec4(0.404508497187473, - 0.154508497187474, 0, - 0.25),
    glm::vec4(0.404508497187473, 0, - 0.25, - 0.154508497187474),
    glm::vec4(- 0.25, 0.404508497187473, 0, - 0.154508497187474),
    glm::vec4(- 0.25, - 0.154508497187474, 0.404508497187473, 0),
    glm::vec4(- 0.25, 0, - 0.154508497187474, 0.404508497187473),
    glm::vec4(- 0.154508497187474, 0.404508497187473, - 0.25, 0),
    glm::vec4(- 0.154508497187474, - 0.25, 0, 0.404508497187473),
    glm::vec4(- 0.154508497187474, 0, 0.404508497187473, - 0.25),
    glm::vec4(0, 0.404508497187473, - 0.154508497187474, - 0.25),
    glm::vec4(0, - 0.25, 0.404508497187473, - 0.154508497187474),
    glm::vec4(0, - 0.154508497187474, - 0.25, 0.404508497187473),
    glm::vec4(- 0.404508497187473, 0.25, 0.154508497187474, 0),
    glm::vec4(- 0.404508497187473, 0.154508497187474, 0, 0.25),
    glm::vec4(- 0.404508497187473, 0, 0.25, 0.154508497187474),
    glm::vec4(0.25, - 0.404508497187473, 0, 0.154508497187474),
    glm::vec4(0.25, 0.154508497187474, - 0.404508497187473, 0),
    glm::vec4(0.25, 0, 0.154508497187474, - 0.404508497187473),
    glm::vec4(0.154508497187474, - 0.404508497187473, 0.25, 0),
    glm::vec4(0.154508497187474, 0.25, 0, - 0.404508497187473),
    glm::vec4(0.154508497187474, 0, - 0.404508497187473, 0.25),
    glm::vec4(0, - 0.404508497187473, 0.154508497187474, 0.25),
    glm::vec4(0, 0.25, - 0.404508497187473, 0.154508497187474),
    glm::vec4(0, 0.154508497187474, 0.25, - 0.404508497187473),
    glm::vec4(- 0.404508497187473, 0.25, - 0.154508497187474, 0),
    glm::vec4(- 0.404508497187473, - 0.154508497187474, 0, 0.25),
    glm::vec4(- 0.404508497187473, 0, 0.25, - 0.154508497187474),
    glm::vec4(0.25, - 0.404508497187473, 0, - 0.154508497187474),
    glm::vec4(0.25, - 0.154508497187474, - 0.404508497187473, 0),
    glm::vec4(0.25, 0, - 0.154508497187474, - 0.404508497187473),
    glm::vec4(- 0.154508497187474, - 0.404508497187473, 0.25, 0),
    glm::vec4(- 0.154508497187474, 0.25, 0, - 0.404508497187473),
    glm::vec4(- 0.154508497187474, 0, - 0.404508497187473, 0.25),
    glm::vec4(0, - 0.404508497187473, - 0.154508497187474, 0.25),
    glm::vec4(0, 0.25, - 0.404508497187473, - 0.154508497187474),
    glm::vec4(0, - 0.154508497187474, 0.25, - 0.404508497187473),
    glm::vec4(- 0.404508497187473, - 0.25, 0.154508497187474, 0),
    glm::vec4(- 0.404508497187473, 0.154508497187474, 0, - 0.25),
    glm::vec4(- 0.404508497187473, 0, - 0.25, 0.154508497187474),
    glm::vec4(- 0.25, - 0.404508497187473, 0, 0.154508497187474),
    glm::vec4(- 0.25, 0.154508497187474, - 0.404508497187473, 0),
    glm::vec4(- 0.25, 0, 0.154508497187474, - 0.404508497187473),
    glm::vec4(0.154508497187474, - 0.404508497187473, - 0.25, 0),
    glm::vec4(0.154508497187474, - 0.25, 0, - 0.404508497187473),
    glm::vec4(0.154508497187474, 0, - 0.404508497187473, - 0.25),
    glm::vec4(0, - 0.404508497187473, 0.154508497187474, - 0.25),
    glm::vec4(0, - 0.25, - 0.404508497187473, 0.154508497187474),
    glm::vec4(0, 0.154508497187474, - 0.25, - 0.404508497187473),
    glm::vec4(- 0.404508497187473, - 0.25, - 0.154508497187474, 0),
    glm::vec4(- 0.404508497187473, - 0.154508497187474, 0, - 0.25),
    glm::vec4(- 0.404508497187473, 0, - 0.25, - 0.154508497187474),
    glm::vec4(- 0.25, - 0.404508497187473, 0, - 0.154508497187474),
    glm::vec4(- 0.25, - 0.154508497187474, - 0.404508497187473, 0),
    glm::vec4(- 0.25, 0, - 0.154508497187474, - 0.404508497187473),
    glm::vec4(- 0.154508497187474, - 0.404508497187473, - 0.25, 0),
    glm::vec4(- 0.154508497187474, - 0.25, 0, - 0.404508497187473),
    glm::vec4(- 0.154508497187474, 0, - 0.404508497187473, - 0.25),
    glm::vec4(0, - 0.404508497187473, - 0.154508497187474, - 0.25),
    glm::vec4(0, - 0.25, - 0.404508497187473, - 0.154508497187474),
    glm::vec4(0, - 0.154508497187474, - 0.25, - 0.404508497187473)
	};

    //static GLuint translate_face_to_indices(GLuint index1, GLuint index2, GLuint index3, GLuint index4, unsigned arrayIndex)
    //{
    //    if (arrayIndex < 3)
    //    {
    //        return faceIndices4D0[index1][arrayIndex];
    //    }
    //    else
    //    {
    //        for (int i = 0; i < 3; i++)
    //        {
    //            bool isOverlap = false;
    //            for (int j = 0; j < 3; j++)
    //            {
    //                if (faceIndices4D0[index1][j] == faceIndices4D0[index2][i])
    //                {
    //                    isOverlap = true;
    //                }
    //            }
    //            if (!isOverlap)
    //            {
    //                return faceIndices4D0[index2][i];
    //            }
    //        }
    //    }
    //}

	static GLuint indices4D0[] =
	{
    113,15,116,110,
    15,113,116,119,
    116,15,119,118,
    15,110,113,109,
    41,6,80,50,
    50,16,60,62,
    110,15,116,112,
    116,15,118,112,
    116,112,118,22,
    6,41,80,71,
    10,44,53,74,
    118,117,119,11,
    118,15,119,117,
    117,11,118,102,
    116,22,118,104,
    118,11,119,104,
    116,118,119,104,
    11,89,104,62,
    104,11,119,89,
    109,15,110,108,
    109,108,110,20,
    110,15,112,108,
    44,10,53,47,
    44,10,47,58,
    41,6,50,37,
    16,50,60,37,
    37,6,50,60,
    87,11,102,60,
    87,21,117,105,
    21,87,117,102,
    11,102,117,87,
    115,113,119,23,
    15,113,119,115,
    15,109,113,115,
    117,15,119,115,
    60,11,88,62,
    102,11,118,88,
    60,88,102,6,
    60,11,102,88,
    60,50,62,88,
    6,50,60,88,
    50,6,80,88,
    11,62,104,88,
    104,22,118,88,
    11,104,118,88,
    108,20,109,96,
    108,15,112,114,
    15,117,118,114,
    112,15,118,114,
    21,102,117,114,
    117,102,118,114,
    112,108,114,14,
    21,102,114,93,
    108,14,112,98,
    20,108,110,98,
    110,108,112,98,
    109,101,115,13,
    109,113,115,101,
    113,23,115,101,
    67,14,71,93,
    19,53,67,47,
    65,67,71,19,
    14,67,71,65,
    53,19,67,65,
    47,10,53,67,
    32,44,58,18,
    47,44,58,32,
    47,32,58,3,
    90,13,105,70,
    60,6,102,75,
    87,60,102,75,
    93,21,102,75,
    75,6,102,93,
    37,6,60,75,
    21,87,102,75,
    89,103,119,23,
    89,11,119,103,
    11,117,119,103,
    87,105,117,103,
    11,87,117,103,
    103,105,117,115,
    117,115,119,103,
    115,23,119,103,
    90,105,111,21,
    13,90,105,111,
    105,21,117,111,
    15,108,109,111,
    15,115,117,111,
    115,105,117,111,
    105,13,111,115,
    15,109,115,111,
    109,13,115,111,
    108,96,109,111,
    109,13,111,96,
    13,90,111,96,
    21,114,117,111,
    114,15,117,111,
    108,15,114,111,
    22,112,118,106,
    6,71,80,106,
    14,71,93,106,
    6,71,106,93,
    93,6,102,106,
    6,88,102,106,
    102,88,118,106,
    88,22,118,106,
    88,22,106,80,
    6,80,88,106,
    93,14,106,114,
    93,102,114,106,
    112,114,118,106,
    112,14,114,106,
    114,102,118,106,
    13,96,109,86,
    20,86,96,74,
    96,20,109,86,
    13,86,101,68,
    101,13,109,86,
    53,10,74,85,
    20,96,108,85,
    20,74,96,85,
    10,74,85,96,
    85,14,98,65,
    98,20,108,85,
    14,98,108,85,
    10,53,67,85,
    65,14,67,85,
    53,65,67,85,
    32,3,47,29,
    26,3,29,37,
    3,29,32,26,
    58,10,81,90,
    10,47,58,81,
    47,3,58,81,
    47,10,67,81,
    21,75,93,81,
    14,65,71,92,
    65,14,98,92,
    98,14,112,92,
    71,80,106,92,
    14,71,106,92,
    106,22,112,92,
    14,106,112,92,
    80,22,106,92,
    10,44,74,64,
    58,10,90,64,
    18,44,58,64,
    44,10,58,64,
    64,10,90,96,
    13,90,96,64,
    10,74,96,64,
    68,64,70,13,
    64,68,70,18,
    58,64,90,70,
    13,70,90,64,
    58,18,64,70,
    86,13,96,64,
    74,86,96,64,
    68,13,86,64,
    14,108,114,99,
    10,90,96,99,
    93,14,114,99,
    21,93,114,99,
    67,14,93,99,
    111,21,114,99,
    108,111,114,99,
    96,90,111,99,
    108,96,111,99,
    90,21,111,99,
    67,10,85,99,
    14,67,85,99,
    85,10,96,99,
    85,96,108,99,
    14,85,108,99,
    21,81,93,99,
    90,21,99,81,
    10,81,90,99,
    10,67,81,99,
    93,67,99,81,
    21,90,105,78,
    58,70,90,78,
    87,21,105,78,
    90,70,105,78,
    75,21,87,78,
    21,75,81,78,
    78,75,81,3,
    21,81,90,78,
    81,58,90,78,
    3,58,81,78,
    6,71,93,55,
    6,41,71,55,
    55,41,71,19,
    6,37,41,55,
    19,47,67,55,
    19,67,71,55,
    71,67,93,55,
    75,6,93,55,
    37,6,75,55,
    37,55,75,3,
    37,41,55,29,
    3,29,37,55,
    19,47,55,29,
    29,3,47,55,
    41,19,55,29,
    3,75,81,55,
    81,75,93,55,
    67,81,93,55,
    67,47,81,55,
    47,3,81,55,
    16,60,62,61,
    89,11,103,61,
    11,60,87,61,
    60,11,62,61,
    11,87,103,61,
    62,11,89,61,
    23,89,103,77,
    89,61,103,77,
    3,26,32,40,
    3,32,58,40,
    32,18,58,40,
    58,18,70,40,
    58,70,78,40,
    3,58,78,40,
    13,68,101,95,
    105,13,115,95,
    70,13,105,95,
    101,23,115,95,
    13,101,115,95,
    68,13,70,95,
    23,103,115,95,
    103,105,115,95,
    23,77,103,95,
    16,37,48,26,
    16,37,60,48,
    26,3,37,48,
    60,37,75,48,
    60,75,87,48,
    75,3,78,48,
    37,3,75,48,
    16,26,48,38,
    75,78,87,48,
    16,38,48,61,
    16,60,61,48,
    61,60,87,48,
    3,40,78,48,
    3,26,40,48,
    38,26,48,40,
    18,68,70,56,
    40,18,70,56,
    70,68,95,56,
    77,23,89,79,
    101,109,113,97,
    109,20,110,97,
    109,110,113,97,
    101,86,109,97,
    86,20,109,97,
    53,65,85,73,
    74,53,85,73,
    20,74,85,73,
    85,65,98,73,
    20,85,98,73,
    110,98,112,100,
    112,22,116,100,
    110,112,116,100,
    98,92,112,100,
    92,22,112,100,
    44,32,47,35,
    47,19,53,35,
    44,47,53,35,
    32,29,47,35,
    29,19,47,35,
    37,16,50,25,
    26,16,37,25,
    41,37,50,25,
    29,26,37,25,
    29,37,41,25,
    19,41,71,59,
    65,19,71,59,
    71,41,80,59,
    65,71,92,59,
    71,80,92,59,
    22,80,88,76,
    50,62,88,76,
    80,50,88,76,
    88,62,104,76,
    22,88,104,76,
    18,64,68,52,
    68,64,86,52,
    64,74,86,52,
    64,44,74,52,
    18,44,64,52,
    78,70,105,7,
    103,87,105,7,
    61,87,103,7,
    77,61,103,7,
    87,78,105,7,
    61,7,77,38,
    40,70,78,7,
    95,77,103,7,
    70,95,105,7,
    95,103,105,7,
    38,40,48,7,
    48,40,78,7,
    61,48,87,7,
    38,48,61,7,
    48,78,87,7,
    70,56,95,7,
    77,7,95,56,
    40,56,70,7,
    7,38,40,56,
    38,7,77,56,
    16,26,38,24,
    16,25,26,24,
    20,98,110,84,
    97,20,110,84,
    20,73,98,84,
    98,100,110,84,
    53,65,73,43,
    53,19,65,43,
    35,19,53,43,
    19,59,65,43,
    92,22,100,82,
    80,22,92,82,
    59,80,92,82,
    76,22,80,82,
    38,56,77,1,
    113,110,116,12,
    97,110,113,12,
    110,100,116,12,
    84,100,110,12,
    97,84,110,12,
    16,38,61,49,
    62,61,89,49,
    16,61,62,49,
    61,77,89,49,
    61,38,77,49,
    77,79,89,49,
    16,24,38,49,
    24,38,49,1,
    49,77,79,1,
    38,1,77,49,
    38,26,40,28,
    32,18,40,28,
    26,32,40,28,
    40,18,56,28,
    38,40,56,28,
    24,26,38,28,
    1,24,38,28,
    1,38,56,28,
    29,19,35,31,
    19,29,41,31,
    29,25,41,31,
    19,41,59,31,
    43,19,59,31,
    35,19,43,31,
    53,43,73,4,
    44,53,74,4,
    53,73,74,4,
    44,35,53,4,
    52,44,74,4,
    4,43,73,51,
    35,43,53,4,
    84,73,98,9,
    65,92,98,9,
    73,65,98,9,
    98,92,100,9,
    65,59,92,9,
    92,82,100,9,
    84,98,100,9,
    43,59,65,9,
    43,65,73,9,
    51,43,73,9,
    59,82,92,9,
    73,9,84,51,
    23,95,101,83,
    23,77,95,83,
    95,68,101,83,
    56,68,95,83,
    77,56,95,83,
    77,23,79,83,
    1,77,79,83,
    1,56,77,83,
    79,1,83,57,
    26,29,32,0,
    32,29,35,0,
    26,25,29,0,
    24,25,26,0,
    0,24,25,27,
    28,26,32,0,
    24,26,28,0,
    25,0,27,31,
    29,31,35,0,
    29,25,31,0,
    41,50,80,2,
    41,25,50,2,
    59,41,80,2,
    59,80,82,2,
    50,76,80,2,
    80,76,82,2,
    27,25,31,2,
    31,25,41,2,
    31,41,59,2,
    2,76,82,54,
    23,113,119,107,
    89,23,119,107,
    113,116,119,107,
    104,89,119,107,
    116,104,119,107,
    79,23,89,107,
    113,12,116,107,
    57,17,63,69,
    84,12,97,63,
    17,57,63,42,
    17,42,63,51,
    56,18,68,46,
    18,52,68,46,
    1,28,56,46,
    28,18,56,46,
    57,1,83,46,
    56,68,83,46,
    1,56,83,46,
    35,31,43,33,
    0,31,35,33,
    4,43,51,33,
    4,35,43,33,
    4,33,51,42,
    17,42,51,33,
    0,27,31,33,
    49,1,79,39,
    39,57,79,69,
    1,57,79,39,
    24,1,49,39,
    57,17,69,39,
    39,17,69,54,
    39,17,54,27,
    22,104,116,94,
    100,22,116,94,
    22,76,104,94,
    76,22,82,94,
    82,22,100,94,
    12,100,116,94,
    54,76,82,94,
    12,94,107,69,
    104,107,116,94,
    107,12,116,94,
    74,20,86,72,
    86,20,97,72,
    73,20,74,72,
    20,84,97,72,
    52,74,86,72,
    20,73,84,72,
    73,51,84,72,
    52,4,74,72,
    4,51,73,72,
    4,73,74,72,
    4,42,51,72,
    52,4,72,42,
    51,42,63,72,
    72,51,84,63,
    84,63,97,72,
    101,97,113,91,
    23,101,113,91,
    97,12,113,91,
    69,57,79,91,
    79,57,83,91,
    23,83,101,91,
    23,79,83,91,
    79,69,91,107,
    12,69,107,91,
    12,107,113,91,
    107,23,113,91,
    79,23,107,91,
    12,69,91,63,
    63,57,69,91,
    63,12,97,91,
    43,31,59,45,
    43,9,51,45,
    9,43,59,45,
    9,59,82,45,
    31,2,59,45,
    27,2,31,45,
    59,2,82,45,
    27,2,45,54,
    2,54,82,45,
    27,17,54,45,
    33,31,43,45,
    27,31,33,45,
    17,33,51,45,
    33,43,51,45,
    27,17,45,33,
    18,28,32,34,
    18,32,44,34,
    32,35,44,34,
    18,44,52,34,
    44,4,52,34,
    28,0,32,34,
    35,4,44,34,
    4,42,52,34,
    32,0,35,34,
    34,42,52,46,
    46,18,52,34,
    28,18,46,34,
    0,33,35,34,
    33,4,35,34,
    4,33,42,34,
    50,16,62,36,
    25,16,50,36,
    50,62,76,36,
    24,16,25,36,
    24,25,27,36,
    16,49,62,36,
    16,24,49,36,
    2,50,76,36,
    25,2,27,36,
    2,25,50,36,
    27,2,54,36,
    54,2,76,36,
    39,27,54,36,
    27,24,36,39,
    24,39,49,36,
    68,86,101,8,
    86,97,101,8,
    68,52,86,8,
    83,68,101,8,
    42,57,63,8,
    46,68,83,8,
    57,46,83,8,
    46,42,52,8,
    8,42,57,46,
    46,52,68,8,
    72,63,97,8,
    42,63,72,8,
    52,42,72,8,
    86,72,97,8,
    52,72,86,8,
    63,91,97,8,
    63,57,91,8,
    91,83,101,8,
    57,83,91,8,
    97,91,101,8,
    12,84,100,66,
    9,82,100,66,
    51,9,84,66,
    84,9,100,66,
    54,17,69,66,
    17,63,69,66,
    63,12,69,66,
    12,63,84,66,
    17,51,63,66,
    63,51,84,66,
    82,54,94,66,
    54,66,69,94,
    69,12,94,66,
    82,94,100,66,
    94,12,100,66,
    45,17,54,66,
    45,54,82,66,
    9,45,82,66,
    45,9,51,66,
    17,45,51,66,
    1,24,28,30,
    24,0,28,30,
    42,17,57,30,
    0,24,27,30,
    46,42,57,30,
    1,46,57,30,
    1,28,46,30,
    0,27,33,30,
    27,17,33,30,
    33,17,42,30,
    17,27,39,30,
    27,24,39,30,
    17,39,57,30,
    39,1,57,30,
    24,1,39,30,
    34,33,42,30,
    0,33,34,30,
    28,34,46,30,
    34,42,46,30,
    28,0,34,30,
    76,62,104,5,
    62,89,104,5,
    49,79,89,5,
    62,49,89,5,
    79,69,107,5,
    104,89,107,5,
    89,79,107,5,
    39,54,69,5,
    49,39,79,5,
    39,69,79,5,
    94,104,107,5,
    69,94,107,5,
    69,54,94,5,
    54,76,94,5,
    94,76,104,5,
    36,39,49,5,
    39,36,54,5,
    54,36,76,5,
    36,62,76,5,
    36,49,62,5
	};
}
