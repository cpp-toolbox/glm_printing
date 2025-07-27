#ifndef GLM_PRINTING_HPP
#define GLM_PRINTING_HPP

#include <iostream>

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/constants.hpp>
#include <iomanip>
#include <sstream>

void print_translation_rotation_scale_of_matrix_transform(const glm::mat4 &transform);

inline std::ostream &operator<<(std::ostream &os, const glm::vec2 &v) { return os << "(" << v.x << ", " << v.y << ")"; }

// inline std::ostream &operator<<(std::ostream &os, const glm::vec3 &v) {
//     return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
// }

std::string vec3_to_string(const glm::vec3 &v, int precision = 1);
std::string vec2_to_string(const glm::vec3 &v, int precision = 1);

namespace glm {
inline std::ostream &operator<<(std::ostream &os, const glm::vec3 &v) {
    return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}
} // namespace glm

inline std::ostream &operator<<(std::ostream &os, const glm::vec4 &v) {
    return os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
}

inline std::ostream &operator<<(std::ostream &os, const glm::mat4 &m) {
    os << "(\n";
    for (int i = 0; i < 4; ++i) {
        os << "  ";
        for (int j = 0; j < 4; ++j) {
            os << m[j][i] << " "; // glm stores matrices in column-major order
        }
        os << "\n";
    }
    return os << ")";
}

#endif // GLM_PRINTING_HPP
