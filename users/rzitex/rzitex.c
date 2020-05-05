#include "rzitex.h"

void update_quad_layer(uint8_t layer1, uint8_t layer2, uint8_t layer3, uint8_t layer4) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else if (IS_LAYER_ON(layer4)) {
    layer_on(layer4);
  } else {
    layer_off(layer3);
  }
}
