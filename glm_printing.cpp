#include "glm_printing.hpp"

void print_translation_rotation_scale_of_matrix_transform(const glm::mat4 &transform) {
    // Extract translation
    glm::vec3 translation(transform[3]);

    // Extract scale
    glm::vec3 scale;
    scale.x = glm::length(glm::vec3(transform[0]));
    scale.y = glm::length(glm::vec3(transform[1]));
    scale.z = glm::length(glm::vec3(transform[2]));

    // Remove scale from rotation matrix
    glm::mat3 rotation_matrix = glm::mat3(transform);
    rotation_matrix[0] /= scale.x;
    rotation_matrix[1] /= scale.y;
    rotation_matrix[2] /= scale.z;

    // Extract rotation as quaternion
    glm::quat rotation = glm::quat_cast(rotation_matrix);
    glm::vec3 euler_angles = glm::eulerAngles(rotation); // Convert to Euler angles

    // Print results
    std::cout << "Translation: (" << translation.x << ", " << translation.y << ", " << translation.z << ")\n";
    std::cout << "Rotation (radians): (" << euler_angles.x << ", " << euler_angles.y << ", " << euler_angles.z << ")\n";
    std::cout << "Rotation (degrees): (" << glm::degrees(euler_angles.x) << ", " << glm::degrees(euler_angles.y) << ", "
              << glm::degrees(euler_angles.z) << ")\n";
    std::cout << "Scale: (" << scale.x << ", " << scale.y << ", " << scale.z << ")\n";
}

std::string vec3_to_string(const glm::vec3 &v, int precision) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(precision);
    oss << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return oss.str();
}
