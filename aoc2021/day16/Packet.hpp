#pragma once
#include "settings.hpp"

class Packet
{
	public:
		Packet(std::string);
		virtual ~Packet();
		

	protected:
		int _version;
		int _id_type;
		int _id_len;
		int _len_sub_packets;
		std::string _sub_packets;
		int _total_len;
		int _padding;
		std::vector<int> _values;
};








