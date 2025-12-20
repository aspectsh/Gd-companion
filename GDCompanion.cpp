#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <random>

using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto menu = this->getChildByID("bottom-menu");
        if (!menu) return true;

        auto spr = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");
        spr->setScale(0.8f);

        auto btn = CCMenuItemSpriteExtra::create(
            spr, this, menu_selector(MenuLayer::onOpenCompanion)
        );

        menu->addChild(btn);
        menu->updateLayout();

        return true;
    }

    void onOpenCompanion(CCObject*) {
        std::vector<std::string> messages = {
            "Keep going!",
            "You got this!",
            "Persistence is key!",
            "Try again!"
        };

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, messages.size() - 1);
        
        FLAlertLayer::create(
            "Companion",
            messages[distrib(gen)],
            "OK"
        )->show();
    }
};
