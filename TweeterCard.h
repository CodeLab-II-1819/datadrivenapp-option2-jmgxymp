#pragma once

#include "ofMain.h"
#include "ofxTextSuite.h"

class TweeterCard {

private:

	float x_position = 390;
	float y_position;
	float height = 0;
	float width = 1140;
	bool onScreen = true;


	int p1;
	int p2;
	int p3;
	int p4;


	string rawText;


	ofxTextBlock dateAndTime;
	ofxTextBlock message;
	ofxTextBlock user;
	ofImage  image;
	ofxTextBlock externalLink;


public:

	TweeterCard();


	void setup(float _yPos, string _rawString);
	void draw();
	void dimentions_manualUpdate();
	void setActive(bool _setActive);
	void updateText(float _yPos, string newText, string dateTime, string user, string image, string url);


	bool isActive();


	float getCardHeight();
	float cardDrawPosition;
};

