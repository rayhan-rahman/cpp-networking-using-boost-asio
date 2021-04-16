#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

int main() {
  asio::io_service ios;
  asio::ip::tcp::acceptor acceptor(ios);

  asio::ip::tcp protocol = asio::ip::tcp::v4();
  boost::system::error_code ec;

  acceptor.open(protocol, ec);
  if (ec.value() != 0) {
    std::cout << "Failed to open the acceptor socket!\n"
              << "Error code = " << ec.value() << ".\n"
              << "Message: " << ec.message() << std::endl;

    return ec.value();
  }
  return 0;
}