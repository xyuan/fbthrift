<?hh // strict
/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

/**
 * Original thrift struct:-
 * Foo
 */
class Foo implements \IThriftStruct {
  use \ThriftSerializationTrait;

  const dict<int, this::TFieldSpec> SPEC = dict[
    1 => shape(
      'var' => 'a',
      'type' => \TType::I64,
    ),
    2 => shape(
      'var' => 'b',
      'type' => \TType::STRING,
    ),
  ];
  const dict<string, int> FIELDMAP = dict[
    'a' => 1,
    'b' => 2,
  ];
  const int STRUCTURAL_ID = 5526046231048010857;
  /**
   * Original thrift field:-
   * 1: i64 a
   */
  public int $a;
  /**
   * Original thrift field:-
   * 2: string b
   */
  public string $b;

  <<__Rx>>
  public function __construct(<<__Soft>> KeyedContainer<string, mixed> $vals = dict[]) {
    $this->a = (int)idx($vals, 'a', 0);
    $this->b = (string)idx($vals, 'b', '');
  }

  public function getName(): string {
    return 'Foo';
  }

}

