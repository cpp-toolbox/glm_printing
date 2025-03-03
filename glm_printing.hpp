#ifndef GLM_PRINTING_HPP
#define GLM_PRINTING_HPP

#include <iostream>
#include <glm/glm.hpp>

inline std::ostream &operator<<(std::ostream &os, const glm::vec3 &v) {
    return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

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
