#include "NodeTransform.hpp"
#include "Cocos.hpp" // IWYU pragma: keep

using namespace geode::prelude;

void NodeTransform::applyTransform(CCNode* node) const {
    node->setPosition(position);
    node->setScale(scale);
    node->setVisible(isVisible);
}

void NodeTransform::setValues(CCNode* node) {
    position = node->getPosition();
    scale = node->getScale();
    isVisible = node->isVisible();
}

matjson::Value matjson::Serialize<NodeTransform>::toJson(NodeTransform const& value) {
    return matjson::makeObject({
        {"position", value.position},
        {"scale", value.scale},
        {"visible", value.isVisible}
    });
}

Result<NodeTransform> matjson::Serialize<NodeTransform>::fromJson(matjson::Value const& value) {
    return geode::Ok(NodeTransform{
        .position = value["position"].as<CCPoint>().unwrapOr(CCPoint{0.0f, 0.0f}),
        .scale = static_cast<float>(value["scale"].asDouble().unwrapOr(1.0)),
        .isVisible = value["visible"].asBool().unwrapOr(true)
    });
}