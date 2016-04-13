# TestFarm
TestFarm is an open platform for automating functional testing of embedded software.
It can be easily interfaced to any off-the-shelf or proprietary peripherals.
Designed as an open architecture, the TestFarm platform is a highly effective tool
that reduces the testing duration and greatly improves the quality of the software delivery.

## Related links
* The main web site : http://www.testfarm.org
* The documentation Wiki : http://www.testfarm.org/doc
* Source repositories on GitHub : https://github.com/testfarm

## License
TestFarm is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

TestFarm is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with TestFarm.  If not, see <http://www.gnu.org/licenses/>.

## Building
### Get source code
```console
$ git clone --recursive https://github.com/testfarm/testfarm.git
$ cd testfarm
```

### Compile
```console
$ make
```

### Generate packages
Resulting packages are available in subdirectory *delivery*:
* TestFarm Core - The main lib and application: testfarm-core
* TestFarm Virtual User - The graphic HMI analysing interface: testfarm-vu
* OCR Agents: tesseract-srv, ocrad-srv, gocr-srv

Debian/Ubuntu packages:
```console
$ make deb
```

RedHat/Fedora packages:
```console
$ make rpm
```
