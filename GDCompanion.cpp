
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <random>

using namespace geode::prelude;

const char* motivationalMessages[] = {
    "Hey! Don't let that wave part get you down. Keep going!",
    "Remember that even the best players started somewhere.",
    "Geometry Dash is all about persistence. You got this!",
    "Take a deep breath and give it another try!",
    "Your skill is building up with every single attempt.",
    "Small goals lead to big victories. Go!",
    "Practice makes perfect! You're getting closer!",
    "Every fail is just one step closer to the win!",
    "Don't give up, the level is almost over!"
};

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto spr = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");
        spr->setScale(0.8f);

        auto btn = CCMenuItemSpriteExtra::create(
            spr, this, menu_selector(MenuLayer::onOpenCompanion)
        );

        auto menu = this->getChildByID("bottom-menu");
        if (menu) {
            menu->addChild(btn);
            menu->updateLayout(); 
        }

        return true;
    }

    void onOpenCompanion(CCObject*) {
        std::random_device rd;
        std::mt19937 gen(rd());
        
        // We have 9 messages now, so we use (0, 8)
        std::uniform_int_distribution<> distrib(0, 8);
        
        const char* message = motivationalMessages[distrib(gen)];
        
        FLAlertLayer::create(
            "Companion Tip",
            message,
            "Close"
        )->show();
    }
}; //
