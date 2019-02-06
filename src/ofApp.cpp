#include "ofApp.h"
#include <locale>

//---file checking---//

void ofApp::tweetsFileGood() {

	while (!tweetsFile.eof()) {

		getline(tweetsFile, temps);
		tweetsDrop.push_back(temps);

	}
}


void ofApp::tweetsFileError() {
	//error code to be added
}


void ofApp::setup(){


	float card_position = 40;
	string tweets_count;


	tweetsFile.open("sampleTweets.csv");
	tweetsFile.good() ? tweetsFileGood() : tweetsFileError();
	tweetsFile.close();


	for (int i = 0; i < 10; i++) {
		searchButton[i].setup(50, quarryButtonHeight, 20, 18, "fonts/CaviarDreams.ttf", baseSearchTerms[i]);
		quarryButtonHeight += searchButton[i].returnHeight();
		quarryButtonHeight += quarryButtonSpaceing;
	}


	for (int i = 0; i < 5; i++) {
		twitterCard[i].setup(card_position, tweetsDrop[i]);
		card_position += twitterCard[i].getCardHeight() + 40;
	}


	//text setup
	rightText1.init("fonts/LemonMilk.otf", 18);
	rightText2.init("fonts/LemonMilk.otf", 18);
	rightText3.init("fonts/LemonMilk.otf", 18);
	rightText4.init("fonts/LemonMilk.otf", 18);
	rightText5.init("fonts/LemonMilk.otf", 18);


	searchingFor.init("fonts/Roboto-Thin.ttf", 18);
	totalFound.init("fonts/Roboto-Thin.ttf", 18);
	totalWithImage.init("fonts/Roboto-Thin.ttf", 18);
	totalDifferentUsers.init("fonts/Roboto-Thin.ttf", 18);
	totalTags.init("fonts/Roboto-Thin.ttf", 18);


	maxPage.init("fonts/Roboto-Thin.ttf", 16);
	minPage.init("fonts/Roboto-Thin.ttf", 16);


	searchingFor.setText("All");


	tweets_count = to_string(tweetsDrop.size());


	if (tweetsDrop.size() >= 1000) {
		tweets_count.insert(tweets_count.end()-3, 1, ',');
	}


	totalFound.setText(tweets_count);


	totalWithImage.setText("99999");
	totalDifferentUsers.setText("99999");
	totalTags.setText("99999");


	//change this
	rightText1.setText("Searching For");
	rightText2.setText("Total found");
	rightText3.setText("Total With Image");
	rightText4.setText("Total different users");
	rightText5.setText("Total @ tags");


	minPage.setText("0");
	maxPage.setText("4");


	//inital search
	searchingFor.setText("Money");
	getTweets("Money");
	newSearch("Money");


	CalibriHeading.load("fonts/Calibri.ttf", 60);
	CalibriHeadingSmall.load("fonts/Calibri.ttf", 25);
	CalibriButton.load("fonts/Calibri.ttf", 18);
	CalibriText.load("fonts/Calibri.ttf", 18);


	//get width and height of text
	CLOSE_bound_box = CalibriButton.getStringBoundingBox("CLOSE", 0, 0);
	TITLE_bound_box = CalibriHeading.getStringBoundingBox("Twitter Twitty", 0, 0);
	TITLESECOND_bound_box = CalibriHeadingSmall.getStringBoundingBox("Made by Jack Mostert", 0, 0);
	HOMETEXT_bound_box = CalibriText.getStringBoundingBox("2. There are three pages to choose from, Home, Feed, Live Feed and settings", 0, 0);
	GOTOFEED_bound_box = CalibriButton.getStringBoundingBox("Go to feed", 0, 0);

	LINK_bound_box = CalibriButton.getStringBoundingBox("Live Feed", 0, 0);


}


void ofApp::update(){

}


void ofApp::Home() {


	ofSetColor(
		font_color_title[0],
		font_color_title[1],
		font_color_title[2],
		font_color_title[3]);
	CalibriHeading.drawString("Twitter Twitty", ofGetWidth() / 2 - TITLE_bound_box.width / 2, 140);

	ofSetColor(
		font_color_subtitle[0],
		font_color_subtitle[1],
		font_color_subtitle[2],
		font_color_subtitle[3]);
	CalibriHeadingSmall.drawString("Made by Jack Mostert", ofGetWidth() / 2 - TITLESECOND_bound_box.width / 2, 180);

	ofSetColor(
		font_color_heading[0],
		font_color_heading[1],
		font_color_heading[2],
		font_color_heading[3]);
	CalibriText.drawString("Information", ofGetWidth() / 2 - HOMETEXT_bound_box.width / 2, 300);

	ofSetColor(
		font_color_normalText[0],
		font_color_normalText[1],
		font_color_normalText[2],
		font_color_normalText[3]);
	CalibriText.drawString("1. The burger icon is where you bring out the menu", ofGetWidth() / 2 - HOMETEXT_bound_box.width / 2, 360);
	CalibriText.drawString("2. There are three pages to choose from, Home, Feed, Live Feed and settings", ofGetWidth() / 2 - HOMETEXT_bound_box.width / 2, 400);
	CalibriText.drawString("NOTE: Live twitter feed requires internet to work", ofGetWidth() / 2 - HOMETEXT_bound_box.width / 2, 440);

	//go to feed button
	ofSetColor(
		background_color_buttonPrim[0],
		background_color_buttonPrim[1],
		background_color_buttonPrim[2],
		background_color_buttonPrim[3]);
	ofDrawRectRounded(ofGetWidth() / 2 - 150, ofGetHeight() - 200, 300, 80, 10);

	//got to feed text
	ofSetColor(
		font_color_buttonText[0],
		font_color_buttonText[1],
		font_color_buttonText[2],
		font_color_buttonText[3]);
	CalibriButton.drawString("Go to feed", (ofGetWidth() / 2 - GOTOFEED_bound_box.width / 2), (ofGetHeight() - 150));


}


void ofApp::draw(){


	switch (pageState) //Changes the page
	{
	case 1:
		Home();
		break;
	case 2:
		Feed();
		break;
	}


}


void ofApp::Feed() {


	ofSetColor(59, 59, 59);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());


	ofSetColor(36, 36, 36);
	ofDrawRectangle(0, 0, sideBarSize, ofGetHeight());
	ofDrawRectangle(ofGetWidth(), 0, -sideBarSize, ofGetHeight());


	for (int i = 0; i < 4; i++) {
		ofSetColor(255, 255, 255);
		twitterCard[i].draw();
	}


	for (int i = 0; i < 10; i++) {
		searchButton[i].draw();
	}


	//right info
	rightText1.draw(ofGetWidth() - sideBarSize / 2 - rightText1.getWidth() / 2, 60);
	rightText2.draw(ofGetWidth() - sideBarSize / 2 - rightText2.getWidth() / 2, 200);
	rightText3.draw(ofGetWidth() - sideBarSize / 2 - rightText3.getWidth() / 2, 340);
	rightText4.draw(ofGetWidth() - sideBarSize / 2 - rightText4.getWidth() / 2, 480);
	rightText5.draw(ofGetWidth() - sideBarSize / 2 - rightText5.getWidth() / 2, 620);


	searchingFor.draw(ofGetWidth() - sideBarSize / 2 - searchingFor.getWidth() / 2, 100);
	totalFound.draw(ofGetWidth() - sideBarSize / 2 - totalFound.getWidth() / 2, 240);
	totalWithImage.draw(ofGetWidth() - sideBarSize / 2 - totalWithImage.getWidth() / 2, 380);
	totalDifferentUsers.draw(ofGetWidth() - sideBarSize / 2 - totalDifferentUsers.getWidth() / 2, 520);
	totalTags.draw(ofGetWidth() - sideBarSize / 2 - totalTags.getWidth() / 2, 660);


	minPage.draw(ofGetWidth() - 300, ofGetHeight() - 70);
	maxPage.draw(ofGetWidth() - 70, ofGetHeight() - 70);


	//debug frame rate
	ofDrawBitmapString(ofGetFrameRate(), 10, 20);


	count = 0;//find out what this is for ???????????????????????????????


}


void ofApp::keyPressed(int key){


	if (key == OF_KEY_LEFT) {


		if (this->page_lower > 0) {
			this->page_lower -= this->pageJump;
			this->page_higher -= this->pageJump;
			this->leftover += pageJump;
			this->pages_shown -= this->pageJump;
		}


	}


	if (key == OF_KEY_RIGHT && endOfFeed == false) {


		this->page_lower += this->pageJump;
		this->page_higher += this->pageJump;
		this->leftover -= pageJump;
		this->pages_shown += this->pageJump;


	}


	if (key == OF_KEY_LEFT || key == OF_KEY_RIGHT) {


		float card_position = 40;
		string temp;
		string temp2;
		minPage.setText(to_string(this->page_lower));
		maxPage.setText(to_string(this->page_higher));


		for (int i = page_lower; i < page_higher; i++) {


			if (message.empty()) {
				temp = "Nothing found";
				temp2 = "Nothing found";
				endOfFeed = true;
			}
			if (i < message.size()) {
				temp = message[i];
				temp2 = dates[i];
				endOfFeed = false;
			}
			else {
				temp = "Error";
				temp2 = "Error";
				endOfFeed = true;
			}


			twitterCard[i - this->pages_shown].updateText(card_position, temp, temp2, "d", "USER", "URL");
			card_position += twitterCard[i - this->pages_shown].getCardHeight() + 40;
		}

	}
}


void ofApp::keyReleased(int key){

}


void ofApp::mouseMoved(int x, int y ){


	for (int i = 0; i < 10; i++) {


		searchButton[i].isMouseOver(x, y);

	}
}


void ofApp::goToFeedButton(int x, int y) {


	//Clicked on button
	int TempX = ofGetWidth() / 2;
	int TempY = ofGetHeight();


	if (x < TempX + 150 && x > TempX - 150) {
		if (y > TempY - 200 && y < TempY - 120) {
			pageState = 2;
		}
	}

}


void ofApp::mousePressed(int x, int y, int button){


	goToFeedButton(x, y);


	for (int i = 0; i < 10; i++) {


		if (searchButton[i].clickCheck(x, y)) {


			//reset
			this->page_lower = 0;
			this->page_higher = 4;
			this->pages_shown = NULL;
			this->minPage.setText("0");
			this->maxPage.setText("4");
			dates.clear();
			message.clear();


			string searchTerm = searchButton[i].GetSearchTerm();
			searchingFor.setText(searchTerm);


			getTweets(searchTerm);
			newSearch(searchTerm);


		}
	}
}


void ofApp::getTweets(string searchBy) {


	string tweets_count;
	stringstream temp;


	//convert to lower case
	for (string::size_type i = 0; i < searchBy.length(); ++i) {
		if (searchBy[i] != ' ') {
			temp.put(tolower(searchBy[i]));
		}
	}


	//get
	tweetsSearched.clear();
	for (int i = 0; i < tweetsDrop.size(); i++) {

		if (tweetsDrop[i].find(searchBy) <= tweetsDrop[i].length()) {


			string Old = tweetsDrop[i];
			string New;


			New = Old.substr(0, 16);
			dates.push_back(New);


			New = Old.substr(Old.find_first_of(',')+1);
			message.push_back(New);


			tweetsSearched.push_back(New);
		}
	}


	//get lower case
	for (int i = 0; i < tweetsDrop.size(); i++) {


		if (tweetsDrop[i].find(temp.str()) <= tweetsDrop[i].length()) {


			string Old = tweetsDrop[i];
			string New;


			New = Old.substr(0, 16);
			dates.push_back(New);


			New = Old.substr(Old.find_first_of(',') + 1);
			message.push_back(New);


			tweetsSearched.push_back(New);
		}
	}


	//count
	tweets_count = to_string(message.size());


	if (message.size() >= 1000) {
		tweets_count.insert(tweets_count.end() - 3, 1, ',');
	}


	totalFound.setText(tweets_count);


	this->leftover = message.size();
}


void ofApp::newSearch(string searchTerm) {


	float card_position = 40;
	string temp;
	string temp2;


	for (int i = page_lower; i < page_higher; i++) {


		(message.empty()) ? temp = "Nothing found" : temp = message[i];
		(dates.empty()) ? temp2 = "Nothing found" : temp2 = dates[i];


		twitterCard[i].updateText(card_position, temp, temp2, "d", "USER", "URL");
		card_position += twitterCard[i].getCardHeight() + 40;
	}

}