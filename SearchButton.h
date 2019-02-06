#pragma once
#include "ofMain.h"
#include "ofxTextSuite.h"

class SearchButton {


private:


	float x_position;
	float y_position;
	float width;
	float height;
	float padding;


	int font_size;
	

	string font;
	string search_quary;
	ofxTextBlock text;


	bool is_mouse_over;


public:


	void setup(float _xPos, float _yPos, float _padding, int _fontSize, string _font, string _toSearchText);
	void draw();


	void updatePosition();
	void changeSearchTerm(string _newTerm);
	void fontChangeSize(int _newSize);
	void fontChangeType(string _newType);
	void hoverEffect();
	void dimentions_ManualUpdate();
	void font_manualUpdate();


	float returnHeight();
	float returnWidth();
	

	void isMouseOver(float mouseX, float mouseY);
	bool clickCheck(float mouseX, float mouseY);


	string GetSearchTerm();


	SearchButton();
};