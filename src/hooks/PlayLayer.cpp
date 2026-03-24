#include <Geode/modify/PlayLayer.hpp>
#include "GJBaseGameLayer.hpp"

using namespace geode::prelude;

struct IVPlayLayer : Modify<IVPlayLayer, PlayLayer> {
    $override
    void pauseGame(bool p0) {
        PlayLayer::pauseGame(p0);
        if (auto uiLayer = this->m_uiLayer) {
            if (auto ivLayer = static_cast<inputs_viewer::InputsViewLayer*>(uiLayer->getChildByID("inputs-viewer"))) {
                ivLayer->releaseAllButtons();
            }
        }
    }
};