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
    "Hey! Don't let that wave part get you down. Keep going!",
    "Remember that even the best players started somewhere.",
    "Geometry Dash is all about persistence. You got this!",
    "Take a deep breath and give it another try!",
    "Your skill is building up with every single attempt.",
    "Small goals lead to big victories. Go!"
};

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;
        auto spr = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");
        spr->setScale(0.8f);
        auto btn = CCMenuItemSpriteExtra::create(spr, this, menu_selector(MenuLayer::onOpenCompanion));
        auto menu = this->getChildByID("bottom-menu");
        if (menu) {
            menu->addChild(btn);
            menu->updateLayout(); 
        } else {
            btn->setPosition({30.0f, 30.0f});
            this->addChild(btn);
        }
        return true;
    }

    void onOpenCompanion(CCObject*) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, 5);
        const char* message = motivationalMessages[distrib(gen)];
        
        // Random colored titles: <cg>=green, <cy>=yellow, <cp>=purple, <cr>=red, <cb>=blue
        const char* colors[] = {"<cg>", "<cy>", "<cp>", "<cr>", "<cb>"};
        std::string title = std::string(colors[distrib(gen) % 5]) + "Companion Tip</c>";

        CompanionPopup::create(title.c_str(), message)->show();
    }
};
