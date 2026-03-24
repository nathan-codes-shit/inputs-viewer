#include "Cocos.hpp"

using namespace geode::prelude;

// CCPoint

matjson::Value matjson::Serialize<CCPoint>::toJson(CCPoint const& value) {
    return std::vector<matjson::Value>{value.x, value.y};
}

geode::Result<cocos2d::CCPoint> matjson::Serialize<CCPoint>::fromJson(matjson::Value const& value) {
    if (value.isObject()) {
        if (value.contains("x") && value.contains("y")) {
            auto x = value["x"].asDouble().unwrapOr(0.0);
            auto y = value["y"].asDouble().unwrapOr(0.0);
            return geode::Ok(CCPoint{static_cast<float>(x), static_cast<float>(y)});
        }
        return Err("Expected object to have \"x\" and \"y\" field");
    } else if (value.isArray()) {
        if (value.asArray().unwrap().size() < 2) return Err("Expected array to have 2 elements");

        auto x = value[0].asDouble().unwrapOr(0.0);
        auto y = value[1].asDouble().unwrapOr(0.0);
        return geode::Ok(CCPoint{static_cast<float>(x), static_cast<float>(y)});
    }

    return Err("Expected json to be an object or an array");
}