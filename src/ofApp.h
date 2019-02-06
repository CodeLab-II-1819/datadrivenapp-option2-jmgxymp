#pragma once

#include "ofMain.h"
#include ".././apps/myApps/myFeed/SearchButton.h"
#include ".././apps/myApps/myFeed/TweeterCard.h"
#include "ofxTextSuite.h"
#include <vector>
#include <fstream>

class ofApp : public ofBaseApp{

	public:


		void Home();
		void Feed();
		void goToFeedButton(int x, int y);


		void setup();
		void update();
		void draw();


		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mousePressed(int x, int y, int button);


		void tweetsFileGood();
		void tweetsFileError();

		void getTweets(string searchBy);
		void newSearch(string searchTerm);


		SearchButton searchButton[10];
		TweeterCard twitterCard[5];
		TweeterCard tempCard;
		

		float quarryButtonHeight = 200;


		int quarryButtonSpaceing = 30;
		int sideBarSize = 350;
		int count;
		int pageState = 1;


		//file
		vector<string> tweetsDrop;
		vector<string> tweetsSearched;


		vector<string> dates;
		vector<string> message;


		ifstream tweetsFile;
		string temps;


		//Information
		string baseSearchTerms[10] = {
			"Money",
			"Politics",
			"Paris",
			"DreamWorks",
			"Uber",
			"Images Only",
			"Tweets with videos",
			"Star wars",
			"Nero",
			"Life" };
		int totalFoundInt;
		int totalWithImageInt;
		int totalDifferentUsersInt;
		int totalAtInt;

		//nav
		int page_lower = 0;
		int page_higher = 4;
		int pageJump = 4;
		int pages_shown;
		int leftover;


		//card
		bool endOfFeed = false;


		//right sideBar titles
		ofxTextBlock rightText1;
		ofxTextBlock rightText2;
		ofxTextBlock rightText3;
		ofxTextBlock rightText4;
		ofxTextBlock rightText5;


		//right sideBar results
		ofxTextBlock searchingFor;
		ofxTextBlock totalFound;
		ofxTextBlock totalWithImage;
		ofxTextBlock totalDifferentUsers;
		ofxTextBlock totalTags;


		//right bottom titles


		//right bottom results
		ofxTextBlock minPage;
		ofxTextBlock maxPage;


		//old code


		ofRectangle CLOSE_bound_box;
		ofRectangle TITLE_bound_box;
		ofRectangle TITLESECOND_bound_box;
		ofRectangle HOMETEXT_bound_box;


		ofRectangle LINK_bound_box;
		ofRectangle GOTOFEED_bound_box;


		//fonts
		ofTrueTypeFont CalibriText;
		ofTrueTypeFont CalibriHeading;
		ofTrueTypeFont CalibriHeadingSmall;
		ofTrueTypeFont CalibriButton;


		//color
		int font_color_title[4] = { 0, 0, 0, 255 };
		int font_color_subtitle[4] = { 70, 70, 70, 255 };
		int font_color_heading[4] = { 10, 214, 159, 255 };
		int font_color_normalText[4] = { 20, 20, 20, 255 };
		int font_color_buttonText[4] = { 255, 255, 255, 255 };
		int font_color_sideNavText[4] = { 255, 255, 255, 255 };
		int font_color_feed_quarryText[4] = { 0, 0, 0, 255 };
		int font_color_feed_cardText[4] = { 0, 0, 0, 255 };

		int background_color_page[4] = { 240, 240, 240, 255 };
		int background_color_buttonPrim[4] = { 10, 214, 159, 255 };
		int background_color_sideNav[4] = { 30, 30, 30, 240 };
		int background_color_card[4] = { 255, 255, 255, 255 };
		int background_color_burgerIcon[4] = { 40, 40, 40, 255 };
};