#include <iostream>
#include <iomanip>
#include "StandardCinema.h"  
#include "VipCinema.h"    

int main() {
    std::cout << std::fixed << std::setprecision(2);

    // 1. Tạo rạp Standard 5 x 6
    StandardCinema stdCin(5, 6);
    std::cout << "STANDARD CINEMA (5 x 6)\n";

    int r = 2, c = 3;

    // Check ghế trống
    std::cout << "Seat (" << r << ", " << c << ") empty? "
              << stdCin.isEmpty(r, c) << "\n";

    // Xem giá ghế
    std::cout << "Price at seat (" << r << ", " << c << "): "
              << stdCin.priceAtSeat(r, c) << " $\n";

    // Đặt ghế
    if (stdCin.book(r, c)) {
        std::cout << "Booked seat (" << r << ", " << c << ") successfully.\n";
    } else {
        std::cout << "Cannot book seat (" << r << ", " << c << ").\n";
    }

    // Check lại ghế đó còn trống không
    std::cout << "Seat (" << r << ", " << c << ") empty after booking? "
              << stdCin.isEmpty(r, c) << "\n";

    // Đặt thêm vài ghế khác
    stdCin.book(0, 0);
    stdCin.book(4, 5);

    // Tính tổng doanh thu rạp Standard
    std::cout << "Total revenue (Standard): "
              << stdCin.revenue() << " $\n\n";


    // Tạo 2 rạp VIP: 1 cái ngày Monday, 1 cái ngày Thursday
    VipCinema vipMon(5, 6, "Monday");    // không giảm giá
    VipCinema vipThu(5, 6, "Thursday");  // giảm 20%

    std::cout << "VIP CINEMA (5 x 6)\n";

    // Đặt cùng một số ghế ở cả hai rạp để so sánh doanh thu
    vipMon.book(2, 3);
    vipMon.book(1, 1);
    vipMon.book(3, 4);

    vipThu.book(2, 3);
    vipThu.book(1, 1);
    vipThu.book(3, 4);

    std::cout << "VIP Monday revenue : " << vipMon.revenue() << " $\n";
    std::cout << "VIP Thursday revenue (20% off): "
              << vipThu.revenue() << " $\n";

    return 0;
}
