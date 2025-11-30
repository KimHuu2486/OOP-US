#include <memory>
#include <iostream>

struct Entity {
    ~Entity() { std::cout << "Entity da bi xoa!\n"; }
};

int main() {
    // // Tạo unique_ptr (Cách chuẩn: dùng make_unique)
    // std::unique_ptr<int> entity1 = std::make_unique<int>(1);
    // std::cout << *entity1 << std::endl;
    // // std::unique_ptr<Entity> entity2 = entity1; // LỖI! Không được copy

    // // Chuyển quyền sở hữu sang entity2
    // std::unique_ptr<int> entity2 = std::move(entity1);

    // if (entity1 == nullptr) std::cout << "entity1 gio la null\n";
    
    // // Khi ra khỏi main, entity2 bị hủy -> tự động gọi delete cho vùng nhớ.

    std::shared_ptr<Entity> ptr1 = std::make_shared<Entity>();
    
    {
        std::shared_ptr<Entity> ptr2 = ptr1; // Copy được!
        std::cout << "So nguoi dang giu: " << ptr1.use_count() << "\n"; // In ra 2
    } // ptr2 bị hủy ở đây, biến đếm giảm còn 1, Entity VẪN SỐNG

    std::cout << "So nguoi dang giu: " << ptr1.use_count() << "\n"; // In ra 1

    return 0;
}