#include <Geode/modify/MenuLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include <random>

using namespace geode::prelude;

class CompanionPopup : public FLAlertLayer {
protected:
    bool init(const char* title, const char* message) {
        if (!FLAlertLayer::init(nullptr, title, message, "Close", nullptr)) return false;
        return true;
    }
public:
    static CompanionPopup* create(const char* title, const char* message) {
        auto ret = new CompanionPopup();
        if (ret && ret->init(title, message)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};

const char* motivationalMessages[] = {
    "Hey! Don't let that wave part get you down. Every fail is one step closer to success. Keep going, you got this!",
    "Just wanted to check in. Remember that even the best players started somewhere. Take a deep breath and give it another try!",
    "That was a tough section! Try taking a short break. Fresh eyes make those jumps feel so much easier. I'm here for you!",
    "Geometry Dash is all about persistence. If you feel stuck, try practicing the end of the level backwards. That's a pro tip!",
    "You're making great progress, even if it doesn't feel like it! Your skill is building up with every single attempt. Never give up!",
    "Today's tip: Focus on one difficult part until you hit it three times in a row. Small goals lead to big victories. Go!"
};

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto spr = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");
        spr->setScale(0.8f);

        auto btn = CCMenuItemSpriteExtra::create(
            spr,
            this,
            menu_selector(MenuLayer::$modify::onOpenCompanion)
        );

        auto menu = this->getChildByID("bottom-menu");
        if (menu) {
            menu->addChild(btn);
            menu->updateLayout(); 
        } else {
            btn->setPosition({30.0f, 30.0f});
            this->addChild(btn);
        }
        
        log::info("GD Companion Mod Initialized!");
        return true;
    }

    void onOpenCompanion(CCObject*) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, 5); 
        const char* message = motivationalMessages[distrib(gen)];

        CompanionPopup::create(
            "<cp>Your GD Companion</c>", 
            message
        )->show();
    }
};
