open Ctypes;

module Def = (F: Cstubs.FOREIGN) => {
  open F;

  let printf = F.foreign("printf", string @-> returning(void));
};
