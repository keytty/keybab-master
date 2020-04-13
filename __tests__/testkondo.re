open Jest;
open Expect;
open! Expect.Operators;
open Keybol;

describe("kondo", () => {
  open Mariekondo.Collapsor;

  module Helper = {
    let stringToKeys = s => s |> Js.String.split("") |> Array.to_list;

    let stringToKeybols = s => s |> stringToKeys |> List.map(keyToKeybol);

    test("stringToKeys", () =>
      "hjkl" |> stringToKeys |> expect |> toEqual(["h", "j", "k", "l"])
    );

    test("stringToKeybols", () =>
      "hjkl" |> stringToKeybols |> expect |> toEqual([H, J, K, L])
    );

    let stk = stringToKeybols;
  };
  open Helper;

  test("123 to keybol", () =>
    123
    |> Shifu.numbersToKeybab
    |> expect
    |> toEqual([Dgt(D1), Dgt(D2), Dgt(D3)])
  );

  test("collapseOneSet 0", () =>
    collapseOneSet([], []) |> expect |> toEqual([])
  );

  test("collapse 0", () =>
    collapse(~vertical=([], []), ~horizontal=([], []))
    |> expect
    |> toEqual(([], []))
  );

  test("collapse 1", () =>
    collapse(
      ~vertical=("28j" |> stk, "53k" |> stk),
      ~horizontal=("72h" |> stk, "65l" |> stk),
    )
    |> expect
    |> toEqual(("25k" |> stk, "7h" |> stk))
  );

  test("order 0", () =>
    collapse(~vertical=([], []), ~horizontal=([], []))
    |> order(Some(J))
    |> expect
    |> toEqual([])
  );

  test("order 1", () =>
    collapse(
      ~vertical=("28j" |> stk, "53k" |> stk),
      ~horizontal=("72h" |> stk, "65l" |> stk),
    )
    |> order(Some(K))
    |> expect
    |> toEqual(["7h" |> stk, "25k" |> stk] |> List.flatten)
  );
});
