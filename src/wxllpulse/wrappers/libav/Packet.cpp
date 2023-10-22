#include "Packet.hpp"

#include <stdexcept>

avmm::Packet::Packet():
	_packet{ av_packet_alloc() }
{
	if(_packet == nullptr)
	{
		throw std::runtime_error("Packet::Packet(): packet allocation failed.");
	}
}

avmm::Packet::~Packet()
{
	av_packet_free(&_packet);
}


