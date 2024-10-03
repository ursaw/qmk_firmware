"""QMK latex macros like in https://getreuer.info/posts/keyboards/macros/index.html"""

from dataclasses import dataclass


@dataclass
class TeXmacro:
    key: str = ""
    """letter to get"""

    upper: bool = False
    """has it an upper case"""

    long: str = ""
    """The LaTeX command. no trailing backslash"""

    def __init__(self, key, long):
        self.key = key
        self.upper = True if len(long.split(','))>1 else False
        self.long = long

    def get_key_code(self):
        """Name of the macro."""
        return f"TEX_{self.key.upper()}"

    def qmk_code(self):
        """C++ code generation."""
        str = f'''   case {self.get_key_code()}:
            if (record->event.pressed) {{
        '''
        larr = self.long.split(',')
        # TODO upper case with shift return |Xi instead of \Xi
        if len(larr)>1:
            str += f'''        if( get_mods() & MOD_BIT(MOD_MASK_SHIFT) ) {{ clear_mods(); SEND_STRING("\\\\{larr[1]} ");add_mods(MOD_MASK_SHIFT);}}
                else                                       {{ SEND_STRING("\\\\{larr[0]} ");}}
            '''
        else:
            str += f'''        SEND_STRING("\\\\{larr[0]} ");
            '''
        str += '''}
      return true;
'''
        print(str)
        return

pass

greek_list = list()
greek_list.append(TeXmacro('a', 'alpha') )
greek_list.append(TeXmacro('b', 'beta') )
greek_list.append(TeXmacro('c', 'chi') )
greek_list.append(TeXmacro('d', 'delta,Delta') )
greek_list.append(TeXmacro('e', 'epsilon') )
greek_list.append(TeXmacro('f', 'frac') )
greek_list.append(TeXmacro('g', 'gamma') )
greek_list.append(TeXmacro('i', 'iota') )
greek_list.append(TeXmacro('k', 'kappa') )
greek_list.append(TeXmacro('l', 'lambda,Lamda') )
greek_list.append(TeXmacro('m', 'mu') )
greek_list.append(TeXmacro('n', 'nu') )
greek_list.append(TeXmacro('o', 'omega,Omega') )
greek_list.append(TeXmacro('p', 'pi,Pi') )
greek_list.append(TeXmacro('s', 'sigma,Sigma') )
#greek_list.append(TeXmacro('t', 'tau') )
greek_list.append(TeXmacro('t', 'theata,Theta') )
greek_list.append(TeXmacro('v', 'varphi') )
greek_list.append(TeXmacro('x', 'xi,Xi') )
greek_list.append(TeXmacro('z', 'zeta') )


for e in greek_list:
    e.qmk_code()


# create custum keycodes
key_list = [x.get_key_code() for x in greek_list]
key_list[0] = f'{key_list[0]} = SAFE_RANGE'
print('enum custom_keycodes {')
for x in key_list:
    print(f"  {x},")
print("};")
pass
