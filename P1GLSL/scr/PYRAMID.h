#ifndef __PYRAMIDFILE__
#define __PYRAMIDFILE__

//Describimos una piramide
//*******************
//Se replican vértices para que cada cara 
//tenga una normal distinta.

//Número de vértices
const int pyramidNVertex = 24; // 3 vértices x 8 caras
const int pyramidNTriangleIndex = 8; // 1 triángulo por cara x 8 cara;


const unsigned int pyramidTriangleIndex[] = {
	//Cara 1 sup
	0,1,2,			
	//Cara 2 sup
	3,4,5,			
	//Cara 3 sup
	6,7,8,			
	//Cara 4 sup
	9,10,11,		
	//Cara 1 inf
	12,13,14,
	//Cara 2 inf
	15,16,17,
	//Cara 3 inf
	18,19,20,
	//Cara 4 inf
	21,22,23,
};

//Posicíon de los vertices
const float pyramidVertexPos[] = { 
	//Cara 1 sup
	 1.0f,	 0.0f,	-1.0f, //0
	 1.0f,	 0.0f,	 1.0f, //1
	 0.0f,	 1.0f,	 0.0f, //2
	 
	//Cara 2 sup		   
	 1.0f,	 0.0f,	 1.0f, //3
	-1.0f,	 0.0f,	 1.0f, //4
	 0.0f,	 1.0f,	 0.0f, //5
	
	//Cara 3 sup		   
   -1.0f,	 0.0f,	 1.0f, //6
   -1.0f,	 0.0f,	-1.0f, //7
	0.0f,	 1.0f,	 0.0f, //8
	
	//Cara 4 sup		   
	-1.0f,	 0.0f,	-1.0f, //9
	 1.0f,	 0.0f,	-1.0f, //10
	 0.0f,	 1.0f,	 0.0f, //11

	 //Cara 1 inf
	 1.0f,	 0.0f,	-1.0f, //12
	 0.0f,	-1.0f,	 0.0f, //13
	 1.0f,	 0.0f,	 1.0f, //14

	//Cara 2 inf		   
	 1.0f,	 0.0f,	 1.0f, //15
	 0.0f,	-1.0f,	 0.0f, //16
	-1.0f,	 0.0f,	 1.0f, //17
	 

	//Cara 3 inf		   
   -1.0f,	 0.0f,	 1.0f, //18
    0.0f,	-1.0f,	 0.0f, //19
   -1.0f,	 0.0f,	-1.0f, //20
	

	//Cara 4 inf		   
	-1.0f,	 0.0f,	-1.0f, //21
	 0.0f,	-1.0f,	 0.0f, //22
	 1.0f,	 0.0f,	-1.0f, //23
 };


//Normal de los vertices
const float pyramidVertexNormal[] = { 
	//Cara 1 sup
	0.0f,	0.0f,	 1.0f, 
	0.0f,	0.0f,	 1.0f, 
	0.0f,	0.0f,	 1.0f, 
	
	//Cara 2 sup		   
	0.0f,	0.0f,	-1.0f, 
	0.0f,	0.0f,	-1.0f, 
	0.0f,	0.0f,	-1.0f, 
	
	//Cara 3 sup		   
	1.0f,	0.0f,	 0.0f, 
	1.0f,	0.0f,	 0.0f, 
	1.0f,	0.0f,	 0.0f, 
	
	//Cara 4 sup		   
	-1.0f,	0.0f,	 0.0f, 
	-1.0f,	0.0f,	 0.0f, 
	-1.0f,	0.0f,	 0.0f, 
	
	//Cara 1 inf
	0.0f,	0.0f,	 1.0f,
	0.0f,	0.0f,	 1.0f,
	0.0f,	0.0f,	 1.0f,

	//Cara 2 inf		   
	0.0f,	0.0f,	-1.0f,
	0.0f,	0.0f,	-1.0f,
	0.0f,	0.0f,	-1.0f,

	//Cara 3 inf		   
	1.0f,	0.0f,	 0.0f,
	1.0f,	0.0f,	 0.0f,
	1.0f,	0.0f,	 0.0f,

	//Cara 4 inf		   
	-1.0f,	0.0f,	 0.0f,
	-1.0f,	0.0f,	 0.0f,
	-1.0f,	0.0f,	 0.0f,
 };


//Color de los vertices
const float pyramidVertexColor[] = { 
	//Cara 1 sup
	1.0f,	0.0f,	 0.0f, 
	1.0f,	0.0f,	 0.0f,
	1.0f,	0.0f,	 0.0f,
	
	//Cara 2 sup		   
	0.0f,	1.0f,	 0.0f, 
	0.0f,	1.0f,	 0.0f,
	0.0f,	1.0f,	 0.0f,
	
	//Cara 3 sup	   
	1.0f,	0.0f,	 0.0f,
	1.0f,	0.0f,	 0.0f,
	1.0f,	0.0f,	 0.0f,
	
	//Cara 4 sup		   
	0.0f,	0.0f,	 1.0f, 
	0.0f,	0.0f,	 1.0f,
	0.0f,	0.0f,	 1.0f,
	
	//Cara 1 inf
	0.0f,	1.0f,	 0.0f,
	0.0f,	1.0f,	 0.0f,
	0.0f,	1.0f,	 0.0f,

	//Cara 2 inf		   
	1.0f,	0.0f,	 0.0f,
	1.0f,	0.0f,	 0.0f,
	1.0f,	0.0f,	 0.0f,

	//Cara 3 inf	   
	0.0f,	0.0f,	 1.0f,
	0.0f,	0.0f,	 1.0f,
	0.0f,	0.0f,	 1.0f,

	//Cara 4 inf		   
	1.0f,	0.0f,	 0.0f,
	1.0f,	0.0f,	 0.0f,
	1.0f,	0.0f,	 0.0f,
 };

//Cood. de textura de los vertices
const float pyramidVertexTexCoord[] = { 
	//Cara 1 sup
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	
	//Cara 2 sup
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,

	//Cara 3 sup	
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	
	//Cara 4 sup
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,

	//Cara 1 inf
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,

	//Cara 2 inf
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,

	//Cara 3 inf	
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,

	//Cara 4 inf
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	
	
 };


const float pyramidVertexTangent[] = { 
	//Cara 1 sup
	0.0f,	0.0f,	 1.0f,
	0.0f,	0.0f,	 1.0f,
	0.0f,	0.0f,	 1.0f,

	//Cara 2 sup		   
	0.0f,	0.0f,	-1.0f,
	0.0f,	0.0f,	-1.0f,
	0.0f,	0.0f,	-1.0f,

	//Cara 3 sup		   
	1.0f,	0.0f,	 0.0f,
	1.0f,	0.0f,	 0.0f,
	1.0f,	0.0f,	 0.0f,

	//Cara 4 sup		   
	-1.0f,	0.0f,	 0.0f,
	-1.0f,	0.0f,	 0.0f,
	-1.0f,	0.0f,	 0.0f,

	//Cara 1 inf
	0.0f,	0.0f,	 1.0f,
	0.0f,	0.0f,	 1.0f,
	0.0f,	0.0f,	 1.0f,

	//Cara 2 inf		   
	0.0f,	0.0f,	-1.0f,
	0.0f,	0.0f,	-1.0f,
	0.0f,	0.0f,	-1.0f,

	//Cara 3 inf		   
	1.0f,	0.0f,	 0.0f,
	1.0f,	0.0f,	 0.0f,
	1.0f,	0.0f,	 0.0f,

	//Cara 4 inf		   
	-1.0f,	0.0f,	 0.0f,
	-1.0f,	0.0f,	 0.0f,
	-1.0f,	0.0f,	 0.0f,
 };

#endif


