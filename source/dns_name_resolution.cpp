#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

int main() {
  std::string host = "host.com";
  std::string port_num = "3333";

  asio::io_service ios;
  asio::ip::tcp::resolver resolver(ios);

  asio::ip::tcp::resolver::query query(
      host, port_num, asio::ip::tcp::resolver::query::numeric_service);
  boost::system::error_code ec;

  asio::ip::tcp::resolver::iterator it = resolver.resolve(query, ec);

  if (ec.value() != 0) {
    std::cout << "Failed to resolve the DNS name.\n"
              << "Error code = " << ec.value() << ".\n"
              << "Message = " << ec.message() << std::endl;

    return ec.value();
  }

  return 0;
}