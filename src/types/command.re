type t =
  | J
  | UDKey(string);

let keyToCommand = key =>
  switch (key) {
  | "j" => J
  | k => UDKey(k)
  };

let validCommands = cs => {
  let filterOutUndefined = c =>
    switch (c) {
    | J => true
    | UDKey(_) => false
    };

  cs |> List.filter(filterOutUndefined);
};
