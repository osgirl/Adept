#
# Autogenerated by Thrift Compiler (0.9.0)
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#
require 5.6.0;
use strict;
use warnings;
use Thrift;

use thrift::adept::common::Types;

# HELPER FUNCTIONS AND STRUCTURES

package thrift::adept::common::JudgmentService_valueOf_args;
use base qw(Class::Accessor);
thrift::adept::common::JudgmentService_valueOf_args->mk_accessors( qw( name ) );

sub new {
                                    my $classname = shift;
                                    my $self      = {};
                                    my $vals      = shift || {};
                                    $self->{name} = undef;
                                    if (UNIVERSAL::isa($vals,'HASH')) {
                                      if (defined $vals->{name}) {
                                        $self->{name} = $vals->{name};
                                      }
                                    }
                                    return bless ($self, $classname);
}

sub getName {
                                    return 'JudgmentService_valueOf_args';
                                  }

sub read {
                                    my ($self, $input) = @_;
                                    my $xfer  = 0;
                                    my $fname;
                                    my $ftype = 0;
                                    my $fid   = 0;
                                    $xfer += $input->readStructBegin(\$fname);
                                    while (1) 
                                    {
                                      $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                                      if ($ftype == TType::STOP) {
                                        last;
                                      }
                                      SWITCH: for($fid)
                                      {
                                        /^1$/ && do{                                        if ($ftype == TType::STRING) {
                                          $xfer += $input->readString(\$self->{name});
                                        } else {
                                          $xfer += $input->skip($ftype);
                                        }
                                        last; };
                                          $xfer += $input->skip($ftype);
                                      }
                                      $xfer += $input->readFieldEnd();
                                    }
                                    $xfer += $input->readStructEnd();
                                    return $xfer;
                                  }

sub write {
                                    my ($self, $output) = @_;
                                    my $xfer   = 0;
                                    $xfer += $output->writeStructBegin('JudgmentService_valueOf_args');
                                    if (defined $self->{name}) {
                                      $xfer += $output->writeFieldBegin('name', TType::STRING, 1);
                                      $xfer += $output->writeString($self->{name});
                                      $xfer += $output->writeFieldEnd();
                                    }
                                    $xfer += $output->writeFieldStop();
                                    $xfer += $output->writeStructEnd();
                                    return $xfer;
                                  }

package thrift::adept::common::JudgmentService_valueOf_result;
use base qw(Class::Accessor);
thrift::adept::common::JudgmentService_valueOf_result->mk_accessors( qw( success ) );

sub new {
                                    my $classname = shift;
                                    my $self      = {};
                                    my $vals      = shift || {};
                                    $self->{success} = undef;
                                    if (UNIVERSAL::isa($vals,'HASH')) {
                                      if (defined $vals->{success}) {
                                        $self->{success} = $vals->{success};
                                      }
                                    }
                                    return bless ($self, $classname);
}

sub getName {
                                    return 'JudgmentService_valueOf_result';
                                  }

sub read {
                                    my ($self, $input) = @_;
                                    my $xfer  = 0;
                                    my $fname;
                                    my $ftype = 0;
                                    my $fid   = 0;
                                    $xfer += $input->readStructBegin(\$fname);
                                    while (1) 
                                    {
                                      $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                                      if ($ftype == TType::STOP) {
                                        last;
                                      }
                                      SWITCH: for($fid)
                                      {
                                        /^0$/ && do{                                        if ($ftype == TType::I32) {
                                          $xfer += $input->readI32(\$self->{success});
                                        } else {
                                          $xfer += $input->skip($ftype);
                                        }
                                        last; };
                                          $xfer += $input->skip($ftype);
                                      }
                                      $xfer += $input->readFieldEnd();
                                    }
                                    $xfer += $input->readStructEnd();
                                    return $xfer;
                                  }

sub write {
                                    my ($self, $output) = @_;
                                    my $xfer   = 0;
                                    $xfer += $output->writeStructBegin('JudgmentService_valueOf_result');
                                    if (defined $self->{success}) {
                                      $xfer += $output->writeFieldBegin('success', TType::I32, 0);
                                      $xfer += $output->writeI32($self->{success});
                                      $xfer += $output->writeFieldEnd();
                                    }
                                    $xfer += $output->writeFieldStop();
                                    $xfer += $output->writeStructEnd();
                                    return $xfer;
                                  }

package thrift::adept::common::JudgmentService_values_args;
use base qw(Class::Accessor);

sub new {
                                    my $classname = shift;
                                    my $self      = {};
                                    my $vals      = shift || {};
                                    return bless ($self, $classname);
}

sub getName {
                                    return 'JudgmentService_values_args';
                                  }

sub read {
                                    my ($self, $input) = @_;
                                    my $xfer  = 0;
                                    my $fname;
                                    my $ftype = 0;
                                    my $fid   = 0;
                                    $xfer += $input->readStructBegin(\$fname);
                                    while (1) 
                                    {
                                      $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                                      if ($ftype == TType::STOP) {
                                        last;
                                      }
                                      SWITCH: for($fid)
                                      {
                                          $xfer += $input->skip($ftype);
                                      }
                                      $xfer += $input->readFieldEnd();
                                    }
                                    $xfer += $input->readStructEnd();
                                    return $xfer;
                                  }

sub write {
                                    my ($self, $output) = @_;
                                    my $xfer   = 0;
                                    $xfer += $output->writeStructBegin('JudgmentService_values_args');
                                    $xfer += $output->writeFieldStop();
                                    $xfer += $output->writeStructEnd();
                                    return $xfer;
                                  }

package thrift::adept::common::JudgmentService_values_result;
use base qw(Class::Accessor);
thrift::adept::common::JudgmentService_values_result->mk_accessors( qw( success ) );

sub new {
                                    my $classname = shift;
                                    my $self      = {};
                                    my $vals      = shift || {};
                                    $self->{success} = undef;
                                    if (UNIVERSAL::isa($vals,'HASH')) {
                                      if (defined $vals->{success}) {
                                        $self->{success} = $vals->{success};
                                      }
                                    }
                                    return bless ($self, $classname);
}

sub getName {
                                    return 'JudgmentService_values_result';
                                  }

sub read {
                                    my ($self, $input) = @_;
                                    my $xfer  = 0;
                                    my $fname;
                                    my $ftype = 0;
                                    my $fid   = 0;
                                    $xfer += $input->readStructBegin(\$fname);
                                    while (1) 
                                    {
                                      $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                                      if ($ftype == TType::STOP) {
                                        last;
                                      }
                                      SWITCH: for($fid)
                                      {
                                        /^0$/ && do{                                        if ($ftype == TType::I32) {
                                          $xfer += $input->readI32(\$self->{success});
                                        } else {
                                          $xfer += $input->skip($ftype);
                                        }
                                        last; };
                                          $xfer += $input->skip($ftype);
                                      }
                                      $xfer += $input->readFieldEnd();
                                    }
                                    $xfer += $input->readStructEnd();
                                    return $xfer;
                                  }

sub write {
                                    my ($self, $output) = @_;
                                    my $xfer   = 0;
                                    $xfer += $output->writeStructBegin('JudgmentService_values_result');
                                    if (defined $self->{success}) {
                                      $xfer += $output->writeFieldBegin('success', TType::I32, 0);
                                      $xfer += $output->writeI32($self->{success});
                                      $xfer += $output->writeFieldEnd();
                                    }
                                    $xfer += $output->writeFieldStop();
                                    $xfer += $output->writeStructEnd();
                                    return $xfer;
                                  }

package thrift::adept::common::JudgmentServiceIf;

use strict;


sub valueOf{
  my $self = shift;
  my $name = shift;

  die 'implement interface';
}

sub values{
  my $self = shift;

  die 'implement interface';
}

package thrift::adept::common::JudgmentServiceRest;

use strict;


sub new {
                                    my ($classname, $impl) = @_;
                                    my $self     ={ impl => $impl };

                                    return bless($self,$classname);
}

sub valueOf{
                                    my ($self, $request) = @_;

                                    my $name = ($request->{'name'}) ? $request->{'name'} : undef;
                                    return $self->{impl}->valueOf($name);
                                  }

sub values{
                                    my ($self, $request) = @_;

                                    return $self->{impl}->values();
                                  }

package thrift::adept::common::JudgmentServiceClient;


use base qw(thrift::adept::common::JudgmentServiceIf);
sub new {
                                    my ($classname, $input, $output) = @_;
                                    my $self      = {};
                                    $self->{input}  = $input;
                                    $self->{output} = defined $output ? $output : $input;
                                    $self->{seqid}  = 0;
                                    return bless($self,$classname);
}

sub valueOf{
  my $self = shift;
  my $name = shift;

                                                                        $self->send_valueOf($name);
                                    return $self->recv_valueOf();
}

sub send_valueOf{
  my $self = shift;
  my $name = shift;

                                    $self->{output}->writeMessageBegin('valueOf', TMessageType::CALL, $self->{seqid});
                                    my $args = new thrift::adept::common::JudgmentService_valueOf_args();
                                    $args->{name} = $name;
                                    $args->write($self->{output});
                                    $self->{output}->writeMessageEnd();
                                    $self->{output}->getTransport()->flush();
}

sub recv_valueOf{
  my $self = shift;

                                    my $rseqid = 0;
                                    my $fname;
                                    my $mtype = 0;

                                    $self->{input}->readMessageBegin(\$fname, \$mtype, \$rseqid);
                                    if ($mtype == TMessageType::EXCEPTION) {
                                      my $x = new TApplicationException();
                                      $x->read($self->{input});
                                      $self->{input}->readMessageEnd();
                                      die $x;
                                    }
                                    my $result = new thrift::adept::common::JudgmentService_valueOf_result();
                                    $result->read($self->{input});
                                    $self->{input}->readMessageEnd();

                                    if (defined $result->{success} ) {
                                      return $result->{success};
                                    }
                                    die "valueOf failed: unknown result";
}
sub values{
  my $self = shift;

                                                                        $self->send_values();
                                    return $self->recv_values();
}

sub send_values{
  my $self = shift;

                                    $self->{output}->writeMessageBegin('values', TMessageType::CALL, $self->{seqid});
                                    my $args = new thrift::adept::common::JudgmentService_values_args();
                                    $args->write($self->{output});
                                    $self->{output}->writeMessageEnd();
                                    $self->{output}->getTransport()->flush();
}

sub recv_values{
  my $self = shift;

                                    my $rseqid = 0;
                                    my $fname;
                                    my $mtype = 0;

                                    $self->{input}->readMessageBegin(\$fname, \$mtype, \$rseqid);
                                    if ($mtype == TMessageType::EXCEPTION) {
                                      my $x = new TApplicationException();
                                      $x->read($self->{input});
                                      $self->{input}->readMessageEnd();
                                      die $x;
                                    }
                                    my $result = new thrift::adept::common::JudgmentService_values_result();
                                    $result->read($self->{input});
                                    $self->{input}->readMessageEnd();

                                    if (defined $result->{success} ) {
                                      return $result->{success};
                                    }
                                    die "values failed: unknown result";
}
package thrift::adept::common::JudgmentServiceProcessor;

use strict;


sub new {
                                      my ($classname, $handler) = @_;
                                      my $self      = {};
                                      $self->{handler} = $handler;
                                      return bless ($self, $classname);
}

sub process {
                                      my ($self, $input, $output) = @_;
                                      my $rseqid = 0;
                                      my $fname  = undef;
                                      my $mtype  = 0;

                                      $input->readMessageBegin(\$fname, \$mtype, \$rseqid);
                                      my $methodname = 'process_'.$fname;
                                      if (!$self->can($methodname)) {
                                        $input->skip(TType::STRUCT);
                                        $input->readMessageEnd();
                                        my $x = new TApplicationException('Function '.$fname.' not implemented.', TApplicationException::UNKNOWN_METHOD);
                                        $output->writeMessageBegin($fname, TMessageType::EXCEPTION, $rseqid);
                                        $x->write($output);
                                        $output->writeMessageEnd();
                                        $output->getTransport()->flush();
                                        return;
                                      }
                                      $self->$methodname($rseqid, $input, $output);
                                      return 1;
}

sub process_valueOf {
                                      my ($self, $seqid, $input, $output) = @_;
                                      my $args = new thrift::adept::common::JudgmentService_valueOf_args();
                                      $args->read($input);
                                      $input->readMessageEnd();
                                      my $result = new thrift::adept::common::JudgmentService_valueOf_result();
                                      $result->{success} = $self->{handler}->valueOf($args->name);
                                      $output->writeMessageBegin('valueOf', TMessageType::REPLY, $seqid);
                                      $result->write($output);
                                      $output->writeMessageEnd();
                                      $output->getTransport()->flush();
}

sub process_values {
                                      my ($self, $seqid, $input, $output) = @_;
                                      my $args = new thrift::adept::common::JudgmentService_values_args();
                                      $args->read($input);
                                      $input->readMessageEnd();
                                      my $result = new thrift::adept::common::JudgmentService_values_result();
                                      $result->{success} = $self->{handler}->values();
                                      $output->writeMessageBegin('values', TMessageType::REPLY, $seqid);
                                      $result->write($output);
                                      $output->writeMessageEnd();
                                      $output->getTransport()->flush();
}

1;
