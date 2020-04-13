open Jest;
open Expect;
open! Expect.Operators;
open Master;
open Keybol;
open Action;

describe("instruction", () => {
  open Instruction;

  test({j|["j", "x"]|j}, () =>
    ["j", "x"]
    |> instruction
    |> expect
    |> toEqual({
         actions: [Move({horizontal: 0, vertical: (-1)})],
         keybab: [J],
         feedback: MsgFeedback("x is undefined"),
         nextAvailables: [J, ...allDigitKeybols],
       })
  );

  test({j|["j", "x", "j", "j"]|j}, () =>
    ["j", "x", "j", "j"]
    |> instruction
    |> expect
    |> toEqual({
         actions: [
           Move({horizontal: 0, vertical: (-1)}),
           Move({horizontal: 0, vertical: (-1)}),
           Move({horizontal: 0, vertical: (-1)}),
         ],
         keybab: [J, J, J],
         feedback: NoFeedback,
         nextAvailables: [J, ...allDigitKeybols],
       })
  );
});
