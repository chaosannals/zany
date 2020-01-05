namespace anx{
	namespace aze{
		struct date;
		
		struct date final{
			enum unit : int{
				MOMENT, SECOND, MINUTE, HOUR,
				DAY, MONTH, YEAR, LENGHT
			};
			date(const int(&raw)[LENGHT],const int(&max)[LENGHT]){
				std::copy_n(raw, LENGHT, this->raw);
				std::copy_n(max, LENGHT, this->max);
			}

			void advance(unit u, int value){
				if (!of_range(u))return;
				int now = raw[u] + value;
				raw[u] = now % max[u];
				int carry = now / max[u];
				if (carry != 0)
					advance(static_cast<unit>(u + 1), carry);
			}
			bool of_range(unit u){
				return u >= 0 && u < LENGHT;
			}
			int peek(unit u){
				return raw[u];
			}
		private:
			int raw[LENGHT];
			int max[LENGHT];
		};
	}
}