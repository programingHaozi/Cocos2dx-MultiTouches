#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    /*
    
    //多点触控需要在AppControllor.mm文件中添加 [eaglView setMultipleTouchEnabled:YES];开启多点触控
    
    auto listener = EventListenerTouchAllAtOnce::create();
    
    listener->onTouchesBegan = [](std::vector<Touch*> ts,Event *e){
        log("onTouchesBegan");
    };
    
    listener->onTouchesMoved = [](std::vector<Touch*> ts,Event *e){
        log("touches moved ,and touch count is %ld",ts.size());
    };
    
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    
    */
    
    Device::setAccelerometerEnabled(true);
    
    auto listener = EventListenerAcceleration::create([](Acceleration *a,Event *e){
        log("a.x:%g,a.y:%g,a.z:%g,a.time:%g",a->x,a->y,a->z,a->timestamp);
        
    });
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    
    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
