#include <Geode/modify/PauseLayer.hpp>
#include <class/IVSettingsLayer.hpp>

using namespace geode::prelude;

struct IVPauseLayer : Modify<IVPauseLayer, PauseLayer> {
    $override
    void customSetup() {
        PauseLayer::customSetup();

        if (auto menu = getChildByID("right-button-menu")) {
            auto settingBtn = CCMenuItemSpriteExtra::create(
                CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png"),
                this, menu_selector(IVPauseLayer::onIVSetting)
            );
            menu->addChild(settingBtn);

            menu->updateLayout();
        }
    }
    void onIVSetting(CCObject*) {
        if (PlayLayer::get()->m_levelSettings->m_platformerMode) {
            inputs_viewer::SettingsLayer::create(inputs_viewer::LevelSettingsType::Platformer, true)->show();
        } else {
            inputs_viewer::SettingsLayer::create(inputs_viewer::LevelSettingsType::Classic, true)->show();
        }
    }
};