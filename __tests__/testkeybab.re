open Jest;
open Keybab;

describe("Expect", () =>
  Expect.(test("toBe", () =>
            expect(1 + 2) |> toBe(3)
          ))
);

describe("Expect.Operators", () => {
  open Expect;
  open! Expect.Operators;

  test("==", () =>
    expect(1 + 2) === 3
  );
});

describe("instruction", () => {
  open Expect;
  open! Expect.Operators;

  test("j key", () =>
    keyToCommand("j") |> expect |> toEqual(J)
  );

  test("x key", () =>
    keyToCommand("x") |> expect |> toEqual(UDKey("x"))
  );

  test("[\"j\", \"x\"]", () =>
    ["j", "x"]
    |> List.map(keyToCommand)
    |> instruction
    |> expect
    |> toEqual({
         actions: [{type_: Move}],
         commands: [J],
         feedback: Feedback("x is undefined"),
         nextAvailable: [J],
       })
  );
});
