#include "SearchButton.h"

SearchButton::SearchButton()
{
}


void SearchButton::setup(float _xPos, float _yPos, float _padding, int _fontSize, string _font, string _toSearchText) {


	//varible setup
	this->x_position = _xPos;
	this->y_position = _yPos;
	this->padding = _padding;
	this->font_size = _fontSize;
	this->font = _font;
	this->search_quary = _toSearchText;
	

	//text setup
	text.init(this->font, this->font_size);
	text.setText(this->search_quary);


	//gets and sets the base width and height
	this->dimentions_ManualUpdate();
}


float SearchButton::returnHeight() {
	return this->height;
}


float SearchButton::returnWidth() {
	return this->width;
}


void SearchButton::draw() {


	if (is_mouse_over) {
		this->hoverEffect();
	}


	ofSetColor(178, 178, 178);
	text.draw(this->x_position, this->y_position);
}


void SearchButton::updatePosition() {

}


void SearchButton::changeSearchTerm(string _newTerm) {


	this->search_quary = _newTerm;


	this->font_manualUpdate();
	this->dimentions_ManualUpdate();
}


void SearchButton::dimentions_ManualUpdate() {
	this->height = text.getHeight() + 15;
	this->width = text.getWidth() + 20;
}


void SearchButton::fontChangeSize(int _newSize) {


	this->font_size = _newSize;


	this->font_manualUpdate();
	this->dimentions_ManualUpdate();
}


void SearchButton::fontChangeType(string _newType) {


	this->font = _newType;


	this->font_manualUpdate();
	this->dimentions_ManualUpdate();

}


void SearchButton::hoverEffect() {

	ofSetColor(0, 0, 0, 100);
	ofDrawRectangle(this->x_position-20, this->y_position-5, this->width+20, this->height+5);

}


void SearchButton::isMouseOver(float mouseX, float mouseY) {

	if (mouseX > this->x_position-20 && mouseX < this->x_position + this->width) {

		if (mouseY > this->y_position-5 && mouseY < this->y_position + this->height) {

			is_mouse_over = true;
		}

		else {

			is_mouse_over = false;
		}
	}

	else {

		is_mouse_over = false;
	}
}


bool SearchButton::clickCheck(float mouseX, float mouseY) {


	if (mouseX > this->x_position - 20 && mouseX < this->x_position + this->width) {

		if (mouseY > this->y_position - 5 && mouseY < this->y_position + this->height) {

			return true;
		}

		else {
			return false;
		}
	}
	else {
		return false;
	}
}


string SearchButton::GetSearchTerm() {
	return this->search_quary;
}


void SearchButton::font_manualUpdate() {


	text.init(this->font, this->font_size);
	text.setText(this->search_quary);
}