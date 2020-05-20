src/crc_catalogue.hpp:
	perl scripts/make_catalogue.pl >$@ || rm $@

clean:
	-rm src/crc_catalogue.hpp
