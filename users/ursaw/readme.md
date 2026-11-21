# ursaw userspace

* `select_word.c/.h`  select word / line (https://getreuer.info/posts/keyboards/select-word)
* `latex_greek.c/.h`  LaTeX greek letters
* `heading_word.c/.h` HEADING_WORDS: types `this is an example` as `T H I S   I S   A N   E X A M P L E`.
  Toggle with your own keycode (e.g. `HD_WORD`), call `process_heading_word(keycode, record, HD_WORD)`
  first in `process_record_user`. Enter ends it (and is sent), Esc ends it (not sent),
  Backspace removes the last letter including its spaces, any other key ends it.
  Details in `heading_word.h`.

Copyright <year> <name> <email> @<github_username>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.