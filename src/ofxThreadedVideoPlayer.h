//
//  ofxThreadedVideoPlayer.h
//  BaseApp
//
//  Created by Oriol Ferrer Mesià on 04/03/14.
//
//

#ifndef BaseApp_ofxThreadedVideoPlayer_h
#define BaseApp_ofxThreadedVideoPlayer_h

#include "ofMain.h"
#include "ofxAVFVideoPlayerExtension.h"

class ofxThreadedVideoPlayer;

struct ofxThreadedVideoPlayerStatus{
	ofxThreadedVideoPlayer* player;
	bool ready;
	string path;
	ofxThreadedVideoPlayerStatus(){ ready = true; player = NULL; }
};

class ofxThreadedVideoPlayer: public ofThread{

public:

	ofxThreadedVideoPlayer();

	void loadVideo(string path);
	void play();
	void stop();

	void setLoopMode(ofLoopType loop);
	bool hasFinished();

	void setPosition(float percent);
	float getPosition();
	float getDuration();

	ofTexture* getTexture();

	void draw(float x, float y, bool drawDebug = false);
	void draw(float x, float y, float w, float h);

	float getWidth();
	float getHeight();

	//public ofEvent api
	//call ofAddListener(v->videoIsReadyEvent, this, &testApp::videoIsReadyCallback);
	//to get notified when the video is ready for playback
	ofEvent<ofxThreadedVideoPlayerStatus>	videoIsReadyEvent;

private:

	void threadedFunction();

	string									videopPath;
	ofLoopType								loopMode;
	bool									loadNow;
	bool									playNow;
	bool									stopNow;
	bool									loaded;
	ofxAVFVideoPlayerExtension *			player;



	bool									needToNotifyDelegate;
};


#endif
