#include <iostream>

struct Price { double px; };
struct Quantity { int qty; };

constexpr Quantity operator ""_qty(unsigned long long int i) {
	auto a = static_cast<int>(i);
	return Quantity{a};
}
constexpr Price operator ""_px(long double d) {
	return Price{static_cast<double>(d)};
}

std::ostream &operator<<(std::ostream &o, Price px) {
	return o << px.px;
}

std::ostream &operator<<(std::ostream &o, Quantity qty) {
	return o << qty.qty;
}

void buyShares(const char *symbol,
               Price price,
               Quantity qty) {
	std::cout << "Bought " << qty << " shares of " << symbol << " at " << price << '\n';
}

int main(int argc, const char *argv[]) {
	buyShares("GOOG", 975.0_px, 800_qty);
}
