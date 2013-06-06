#include "Animation.h"


//int Rule::GetOldFetcherDirectory()
//{
//	return m_OldFetcher_directory;
//}
//
//int Rule::GetNewFetcherDirectory()
//{
//	return m_NewFetcher_directory;
//}
//
//DIRECTION Rule::GetOldDirection()
//{
//	return m_OldDirection;
//}
//
//DIRECTION Rule::GetNewDirection()
//{
//	return m_NewDirection;
//}
//
//
//int Rule::GetOldPosition()
//{
//	return m_OldPosition;
//}
//
//int Rule::GetNewPosition()
//{
//	return m_NewPosition;
//}

Animation::Animation()
{

}


Animation::Animation(std::string a_name, 	
					int a_startFrame,
					int a_endFrame,
					bool a_permanent,
					int a_xPosition,
					int a_yPosition,
					int a_currentFrame) {
	this->m_name = a_name;
	this->m_startFrame = a_startFrame;
	this->m_endFrame = a_endFrame;
	this->m_permanent = a_permanent;
	this->m_xPosition = a_xPosition;
	this->m_yPosition = a_yPosition;
	this->m_currentFrame = a_currentFrame;
}



Animation::~Animation()
{

}


std::string Animation::GetName() {
	return m_name;
}

int Animation::GetStartFrame() {

	return m_startFrame;
}

int Animation::GetEndFrame() {
	return m_endFrame;
}

bool Animation::IsPermanent() {
	return m_permanent;
}

int Animation::GetXPosition() {
	return m_xPosition;
}

int Animation::GetYPosition() {
	return m_yPosition;
}

int Animation::GetCurrentFrame() {
	return m_currentFrame;
}





//Rule::Rule(int a_OldFetcher_directory, int a_NewFetcher_directory,
//			 DIRECTION a_OldDirection, DIRECTION a_NewDirection,
//			 int a_OldPosition, int a_NewPosition)
//{
//	this->m_OldFetcher_directory 	= a_OldFetcher_directory;
//	this->m_NewFetcher_directory 	= a_NewFetcher_directory;
//	this->m_OldDirection 			= a_OldDirection;
//	this->m_NewDirection			= a_NewDirection;
//	this->m_OldPosition				= a_OldPosition;
//	this->m_NewPosition				= a_NewPosition;
//}
