let c_headers = "#include <stdio.h>";

let () = {
  let mode = Sys.argv[1];
  let fname = Sys.argv[2];
  let oc = open_out_bin(fname);
  let format = Format.formatter_of_out_channel(oc);
  let fn =
    switch (mode) {
    | "ml" => Cstubs.write_ml
    | "c" =>
      Format.fprintf(format, "%s@\n", c_headers);
      Cstubs.write_c;
    | _ => assert(false)
    };

  fn(
    ~concurrency=Cstubs.unlocked,
    format,
    ~prefix="demo",
    (module Demo_stubs.Def),
  );
  Format.pp_print_flush(format, ());
  close_out(oc);
};
