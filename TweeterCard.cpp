#include "TweeterCard.h"

TweeterCard::TweeterCard()
{
}


void TweeterCard::setup(float _yPos, string _rawString) {


	this->y_position = _yPos;


	this->dateAndTime.init("fonts/Calibri.ttf", 16);
	this->message.init("fonts/Roboto-Thin.ttf", 16);
	this->user.init("fonts/CaviarDreams.ttf", 16);
	this->externalLink.init("fonts/Calibri.ttf", 16);


	this->dateAndTime.setText("13/03/2015 13:03");
	this->message.setText(_rawString);
	this->message.wrapTextX(1120);
	this->user.setText("User Name");
	this->externalLink.setText("Link to twitter");


	this->dimentions_manualUpdate();


	this->cardDrawPosition = this->x_position + 10;
}


void TweeterCard::draw() {


	if (onScreen == true) {

		ofDrawRectRounded(this->x_position, this->y_position, this->width, this->height, 10);
		this->dateAndTime.draw(this->cardDrawPosition, this->p1);
		this->message.draw(this->cardDrawPosition, this->p2);
		this->user.draw(this->cardDrawPosition, this->p3);
		this->externalLink.draw(this->cardDrawPosition, this->p4);
	}

}


void TweeterCard::dimentions_manualUpdate() {


	int temp = 10;


	this->p1 = this->y_position + 10;
	temp += dateAndTime.getHeight() + 20;


	this->p2 = y_position + temp;
	temp += message.getHeight() + 20;


	this->p3 = y_position + temp;
	temp += user.getHeight() + 20;


	this->p4 = y_position + temp;


	this->height = 0;
	this->height += this->dateAndTime.getHeight();
	this->height += 20;
	this->height += this->user.getHeight();
	this->height += 20;
	this->height += this->message.getHeight();
	this->height += 20;
	this->height += this->externalLink.getHeight();
	this->height += 20;
}


float TweeterCard::getCardHeight() {
	return this->height;
}


void TweeterCard::setActive(bool _setActive) {
	this->onScreen = _setActive;
}


bool TweeterCard::isActive() {
	return this->onScreen;
}

void TweeterCard::updateText(float _yPos, string newText, string dateTime, string user, string image, string url) {


	this->y_position = _yPos;
	this->dateAndTime.setText(dateTime);
	this->message.setText(newText);
	this->message.wrapTextX(1120);

	this->dimentions_manualUpdate();


}